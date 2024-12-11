#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <vector>
#include <SDL2/SDL.h>
#include "Sprite.h"
#include <SDL.h>

class GameEngine {
    public:
    GameEngine();
    ~GameEngine();

    bool init();
    void addSprite(Sprite* sprite);
    void removeSprite(Sprite* sprite);
    void run();
    void clean();


    private:
    SLD_WINDOW* window;
    SDL_RENDERER* renderer;
    bool isRunning;
    void handleEvents();
    void update();
    void render();
}

#endif
