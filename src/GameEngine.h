#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <vector>
#include <SDL2/SDL.h>
#include "Sprite.h"

class GameEngine {
    public:
    GameEngine();
    ~GameEngine();

    void init();
    void addSprite(reng::Sprite* sprite);
 
    void run();
    void clean();


    private:
    std::vector<reng::Sprite*> sprites;
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool isRunning;
    void handleEvents();
    void update();
    void render();
};

#endif
