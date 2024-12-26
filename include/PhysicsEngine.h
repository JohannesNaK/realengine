#ifndef PHYSICSENGINE_H
#define PHYSICSENGINE_H
#include "Vector.h"
#include <vector>
#include <queue>
#include "Event.h"
#include "EventTrigger.h"
#include "SpriteMoveTrigger.h"
#include "EventWrapper.h"
#include <functional>
class GameEngine;
namespace  reng {
    class Sprite;
    class PhysicsEngine{
    public:
        PhysicsEngine();
        void move(Sprite& sprite, Vector velocity);
 
        void addMoveListener(std::function<void(SpriteMoveTrigger&)> listener);
        void proccessQueuedEvents();
    private:
    Event<SpriteMoveTrigger>* moveEvent;
 
    };
   
};
#endif