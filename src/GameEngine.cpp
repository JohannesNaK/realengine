#include <iostream>
#include "GameEngine.h"
#include "Sprite.h"
#include "PhysicsEngine.h"
#include "EventWrapper.h"
#include "KeyboardTrigger.h"
#include <unordered_map>
#include <algorithm>
#include <functional>
namespace reng {
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
physicsEngine = new reng::PhysicsEngine();
 
} 

GameEngine::~GameEngine() {
    clean();
}

//Initialize game engine
bool GameEngine::init() {
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    camera = new Camera(renderer,nullptr);
    isRunning = true;
    return true;
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
void GameEngine::addSprite(reng::Sprite* sprite) {
    sprites.push_back(sprite);
}
reng::PhysicsEngine* GameEngine::getPhysicsEngine(){
    return physicsEngine;
}
//Remove sprite from engine
void GameEngine::removeSprite(reng::Sprite* sprite) {
   auto it = std::remove(sprites.begin(), sprites.end(), sprite);
    if (it != sprites.end()) {
        sprites.erase(it, sprites.end()); // Remove the sprite
    }
}
 
//Run game loop 
void GameEngine::run() {
    while (isRunning) {
        handleEvents();
        handlePhysics();
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
    while (SDL_PollEvent(&event)) {        
      //Manage inputs, ask group if input should be on a seperate thread? 
        switch (event.type){
            case SDL_QUIT: isRunning = false;
             break;

            case SDL_KEYUP:
          
                keyboardEvent->addTrigger(KeyboardTrigger("Key pressed",KeyboardTrigger::KeyState::RELEASED, keyName(&event.key)));
                addEventToQueue(static_cast<EventWrapper*>(keyboardEvent));
                break;
             case SDL_KEYDOWN:
           
                keyboardEvent->addTrigger(KeyboardTrigger("Key released",KeyboardTrigger::KeyState::PRESSED, keyName(&event.key)));
                addEventToQueue(static_cast<EventWrapper*>(keyboardEvent));
                break;
        }
      while (!queuedEvents.empty()){
            queuedEvents.front()->notifyListeners();
            queuedEvents.pop();
            
            }
        
    }
       
}

void GameEngine::handlePhysics(){
           

      
}

//Update game state
void GameEngine::update() {
     
  
    for (auto* sprite : sprites) {
        if (camera != nullptr && camera->update() && sprite != camera->getSprite()){
           Vector pos = sprite->getPosition()-camera->getOrgin();
            sprite->setPosition(pos);
        }
        sprite->tick();
    }
    camera->setUpdate(false);
}

 
void GameEngine::render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); //Black background
    SDL_RenderClear(renderer);      //Clear screen

    for (auto* sprite : sprites) {
        sprite->draw(renderer);
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
    SDL_Quit();
}
}