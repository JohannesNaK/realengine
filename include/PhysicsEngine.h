#ifndef PHYSICSENGINE_H
#define PHYSICSENGINE_H
#include "Vector.h"
#include <vector>
#include <queue>
#include "Event.h"
#include "EventTrigger.h"
#include "SpriteMoveTrigger.h"
#include "CollisionTrigger.h"
#include "EventWrapper.h"
#include <unordered_map>
#include <functional>
 
namespace  reng {
    class Sprite;
    class GameEngine;
    class PhysicsEngine{
    
    public:
        PhysicsEngine(GameEngine* gameEngine);
        void move(Sprite& sprite, Vector velocity);
        void addMoveListener(std::function<void(SpriteMoveTrigger&)> listener);
        void addCollisionListener(std::function<void(CollisionTrigger&)> listener);
        void proccessQueuedEvents();
        void enableBoundaries(bool enable);
        Event<CollisionTrigger>* getCollisionEventHandler();
    private:
    std::unordered_map<Sprite*, Sprite*> collisions;
    bool checkCollision(Vector sPos, Vector sBottom, Vector sourcePos, Vector sourceBottom);
    GameEngine* gameEngine;
    Event<SpriteMoveTrigger>* moveEvent;
    Event<CollisionTrigger>* collisionEvent;
     void collisionListener(Sprite& source);
    bool enforcaBoundaries;

    };
   
};
#endif