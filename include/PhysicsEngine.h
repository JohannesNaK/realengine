#ifndef PHYSICSENGINE_H
#define PHYSICSENGINE_H
#include "Vector.h"
#include <vector>
#include <queue>
class GameEngine;
namespace  reng {
    class Sprite;
    class PhysicsEngine{
    public:
        PhysicsEngine(GameEngine* GameEngine);
        bool addSprite(Sprite* sprite);
        void move(Sprite* sprite, Vector velocity);
    private:
    GameEngine* gameEngine;
    };
   
};
#endif