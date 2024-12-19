#include <iostream>
#include "GameEngine.h"
#include "Sprite.h"
#include "PhysicsEngine.h"
#include <algorithm>

SDL_Window* GameEngine::window = nullptr;
SDL_Renderer* GameEngine::renderer = nullptr;
bool GameEngine::isRunning = false;
std::vector<reng::Sprite*> GameEngine::sprites;
reng::PhysicsEngine* GameEngine::physicsEngine = new reng::PhysicsEngine();

GameEngine::GameEngine() {
   
} 

GameEngine::~GameEngine() {
    clean();
}

//Initialize game engine
bool GameEngine::init() {
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    isRunning = true;
 

    return true;
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
        //Handle physics events
        handlePhysics();
        update();
        render();
        SDL_Delay(16); //~60 FPS
    }
}

//Handle input
void GameEngine::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {         
        if (event.type == SDL_QUIT) {
            isRunning = false;
        }

        // HANDLE DIFFERENT EVENTS
    }
}

void GameEngine::handlePhysics(){
    physicsEngine->proccessQueuedEvents();
}

//Update game state
void GameEngine::update() {
    for (auto* sprite : sprites) {
        sprite->tick();
    }
}

//Render all sprites
void GameEngine::render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); //Black background
    SDL_RenderClear(renderer);      //Clear screen

    for (auto* sprite : sprites) {
        sprite->draw(renderer);
    }

    SDL_RenderPresent(renderer);       //Update screen
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

    SDL_Quit();
}