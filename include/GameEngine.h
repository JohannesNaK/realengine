#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <vector>
#include <SDL2/SDL.h>
#include "PhysicsEngine.h"
#include "Sprite.h"

namespace reng {
    class Sprite;   //Declaration of
}
class GameEngine {
    public:
        GameEngine();
        ~GameEngine();
        static bool init();
        static void addSprite(reng::Sprite* sprite);
        static void removeSprite(reng::Sprite* sprite);
        static void run();
        static void clean();


    private:
        static reng::PhysicsEngine* physicsEngine;
        static std::vector<reng::Sprite*> sprites;
        static SDL_Window* window;
        static SDL_Renderer* renderer;
        static bool isRunning;

        static void handleEvents();
        static void handlePhysics();
        static void update();
        static void render();
};

#endif
