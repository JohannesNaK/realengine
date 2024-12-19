#ifndef PHYSICSENGINE_H
#define PHYSICSENGINE_H
#include "Vector.h"
#include <vector>
#include <queue>
#include "Event.h"
#include "EventCause.h"
#include "SpriteMoveTrigger.h"
#include "EventWrapper.h"
class GameEngine;
namespace  reng {
    class Sprite;
    class PhysicsEngine{
    public:
        PhysicsEngine();
        void move(Sprite& sprite, Vector velocity);
        void proccessQueuedEvents();
    private:
    Event<SpriteMoveTrigger>* moveEvent;
    std::queue<EventWrapper*> queuedEvents;
    static bool testMoveListener(SpriteMoveTrigger& trigger);
    };
   
};
#endif