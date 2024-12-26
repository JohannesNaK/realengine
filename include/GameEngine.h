#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <vector>
#include <SDL2/SDL.h>
#include "PhysicsEngine.h"
#include "Sprite.h"
#include "KeyboardTrigger.h"
#include "Event.h"
#include <queue>
#include <functional>
#include <unordered_map>
namespace reng {
    class Sprite;   
    class GameEngine {
    public:
        static GameEngine* getInstance();
        void operator=(const GameEngine&) = delete;
        bool init();
         SDL_Renderer* getRenderer(){ return renderer; }
         void addKeyListener(std::function<void(KeyboardTrigger&)> keyTrigger);
         void addSprite(Sprite* sprite);
         void removeSprite(Sprite* sprite);
         void run();
         void clean();
         void addEventToQueue(EventWrapper* wraper);

       PhysicsEngine* getPhysicsEngine();
    private:
        GameEngine();
        ~GameEngine();
        static GameEngine* instance;
        std::unordered_map<char,KeyboardTrigger> keyTriggers;
       PhysicsEngine* physicsEngine;
       Event<KeyboardTrigger>* keyboardEvent;
        std::vector<reng::Sprite*> sprites;
        SDL_Window* window;
        SDL_Renderer* renderer;
        bool isRunning;
        std::queue<EventWrapper*> queuedEvents;
         void handleEvents();
         void handlePhysics();
         void update();
         void render();
};
};
#endif
