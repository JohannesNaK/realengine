#ifndef PHYSICSENGINE_H
#define PHYSICSENGINE_H
#include "Vector.h"
#include <vector>
#include <queue>
#include "Event.h"
#include "SpriteMove.h"
#include <memory>
class GameEngine;
namespace  reng {
    class Sprite;
    class PhysicsEngine{
    public:
        PhysicsEngine(GameEngine* GameEngine);
        bool addSprite(Sprite* sprite);
        void moveRequest(Sprite& sprite, Vector velocity);
        void pollEvents();
        void setMoveEvent( Event<SpriteMove>* ev);
            
    private:
      GameEngine* gameEngine;
       Event<SpriteMove>* ev;
    };
   
};
#endif