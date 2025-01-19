#include <iostream>
#include "GameEngine.h"
#include "Sprite.h"
 
#include "EventWrapper.h"
#include "KeyboardTrigger.h"
 
#include <algorithm>
#include <functional>

namespace reng {
const std::unordered_map<SDL_Keycode, char> GameEngine::arrowToWASD = {
    {SDLK_UP, 'w'},   
    {SDLK_LEFT, 'a'}, 
    {SDLK_DOWN, 's'}, 
    {SDLK_RIGHT, 'd'} 
};
GameEngine* GameEngine::instance = nullptr;
GameEngine* GameEngine::getInstance(){
    if (instance == nullptr)
        instance = new  GameEngine();
    return instance;
}
GameEngine::GameEngine() : camera(nullptr) {
window = nullptr;
renderer = nullptr;
isRunning = false;
queuedEvents = {};
camera = nullptr;
GameEngine::sprites = {};
keyboardEvent = new Event<KeyboardTrigger>("Keyboard event");
physicsEngine = new PhysicsEngine(this);
 
} 

GameEngine::~GameEngine() {
    clean();
}

//Initialize game engine
bool GameEngine::init() {
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    window = SDL_CreateWindow("Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    camera = new Camera(renderer,nullptr);
    resHandler = new ResourceHandler();
    windowHeight = 600;
    windowWidth = 800;
    isRunning = true;
    return true;
}

int GameEngine::getWindowWidth() const {
    return windowWidth;
}

int GameEngine::getWindowHeight() const {
    return windowHeight; 
}

void GameEngine::setCameraFollowSprite(Sprite* sprite){
    camera->setSprite(sprite);
}
void GameEngine::addKeyListener(std::function<void(KeyboardTrigger&)> listener){
    keyboardEvent->addListener(listener);
}
void GameEngine::addEventToQueue(EventWrapper* wrapper){
    queuedEvents.push(wrapper);
}
//Add sprite to engine
void GameEngine::addSprite(reng::Sprite* sprite){
    sprites.push_back(sprite);
}
std::vector<Sprite*> GameEngine::getSprites() const {
    return sprites;
}
reng::PhysicsEngine* GameEngine::getPhysicsEngine(){
    return physicsEngine;
}
//Remove sprite from engine
void GameEngine::removeSprite(reng::Sprite* sprite) {
   auto it = std::remove(sprites.begin(), sprites.end(), sprite);
    if (it != sprites.end()) {
        sprites.erase(it, sprites.end());
    }   
}
 
//Run game loop 
void GameEngine::run() {
    while (isRunning) {
        handleEvents();
        update();
        render();
        SDL_Delay(16); //~60 FPS
    }
}
const char keyName(SDL_KeyboardEvent* key){
    return *SDL_GetKeyName(key->keysym.sym);
}
  
//Handle input
void GameEngine::handleEvents() {
    SDL_Event event;
    //Switched from while to an if statement, issues when holding down keys causes the event system to execute ALL SDL events first, which results in missmatched input.
    if (SDL_PollEvent(&event)) {        
      //Manage inputs, ask group if input should be on a seperate thread? 
        switch (event.type){
            case SDL_QUIT: isRunning = false; break;
            case SDL_KEYUP: {
                KeyboardTrigger* keyTrigger;
                if (arrowToWASD.count(event.key.keysym.sym)){
                    char mappedKey = arrowToWASD.at(event.key.keysym.sym);
                    keyTrigger = new KeyboardTrigger("Key released",KeyboardTrigger::KeyState::RELEASED, mappedKey);
                }
                   else
                        keyTrigger = new KeyboardTrigger("Key released",KeyboardTrigger::KeyState::RELEASED, keyName(&event.key));
                 
                keyboardEvent->addTrigger(keyTrigger);
                addEventToQueue(static_cast<EventWrapper*>(keyboardEvent));
                break;
            }
                
            case SDL_KEYDOWN: {
                KeyboardTrigger* keyTrigger;
                 if (arrowToWASD.count(event.key.keysym.sym)){
                    char mappedKey = arrowToWASD.at(event.key.keysym.sym);
                    keyTrigger = new KeyboardTrigger("Key pressed",KeyboardTrigger::KeyState::PRESSED, mappedKey);
                   } else
                     keyTrigger = new KeyboardTrigger("Key pressed",KeyboardTrigger::KeyState::PRESSED, keyName(&event.key));
                keyboardEvent->addTrigger(keyTrigger);
                addEventToQueue(static_cast<EventWrapper*>(keyboardEvent));
                break;
            }
        }    
    }
    while (!queuedEvents.empty()){
        queuedEvents.front()->notifyListeners();
        queuedEvents.pop();    
    }
}

//Update game state
void GameEngine::update() {
    std::vector<Sprite*> toRemove;

    //TODO: let the camera handle all render.
    //TODO: dont render sprites that are not within camera distance.
    for (auto* sprite : sprites) {
        if (camera != nullptr && camera->update() && sprite != camera->getSprite()){
            //Offsetting every sprite to make the camera centralized.
            Vector pos = sprite->getPosition()-camera->getOrgin();
            sprite->setPosition(pos);
        }
        sprite->tick();
    }
    for(auto iter = sprites.begin(); iter != sprites.end();){
        if((*iter)->isRemoved()){
            delete *iter;
            iter = sprites.erase(iter);
        }
        else
            iter++;
    }
    camera->setUpdate(false);
}

 
void GameEngine::render() {
       
  //TODO: let the camera handle all render.
  //TODO: dont render sprites that are not within camera distance.
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  
    SDL_RenderClear(renderer);       

    for (auto* sprite : sprites) {
        sprite ->draw(renderer);
    }
    
    SDL_RenderPresent(renderer);   
}

//Clean up resources
void GameEngine::clean() {
    if (renderer) {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }

    if (window) {
        SDL_DestroyWindow(window);
        window = nullptr;
    }
    delete camera;
    delete keyboardEvent;
    delete physicsEngine;
    delete resHandler;
    SDL_Quit();
}
}