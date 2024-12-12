#include <iostream>
#include "GameEngine.h"

GameEngine::GameEngine() {
      window = nullptr;
    renderer = nullptr;
    isRunning = false; 
} 

GameEngine::~GameEngine() {
    clean();
}

void GameEngine::init() {
    
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    isRunning = true;
   
}

void GameEngine::addSprite(reng::Sprite* sprite) {
    sprites.push_back(sprite);
}

 
 
void GameEngine::run() {
    while (isRunning) {
        handleEvents();
        update();
        render();
        SDL_Delay(16); //~60 FPS
    }
}

void GameEngine::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {         
        if (event.type == SDL_QUIT) {
            isRunning = false;
        }

        // HANDLE DIFFERENT EVENTS
    }
}

void GameEngine::update() {
    for (auto* sprite : sprites) {
        sprite->tick();
    }
}

void GameEngine::render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); //Black background
    SDL_RenderClear(renderer);      //Clear screen

    for (auto* sprite : sprites) {
        sprite->draw();
    }

    SDL_RenderPresent(renderer);       //Update screen
}

void GameEngine::clean() {
    if (renderer) {
        SDL_DestroyRenderer(renderer);
    }

    if (window) {
        SDL_DestroyWindow(window);
    }

    SDL_Quit();
}