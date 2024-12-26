#ifndef PHYSICSENGINE_H
#define PHYSICSENGINE_H
#include "Vector.h"
#include <vector>
#include <queue>
#include "Event.h"
#include "EventTrigger.h"
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
    static void testMoveListener(SpriteMoveTrigger& trigger);
    };
   
};
#endif