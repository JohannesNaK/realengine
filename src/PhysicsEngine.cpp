#include "PhysicsEngine.h"
#include "GameEngine.h"
#include "Vector.h"
#include "Sprite.h"
#include "SpriteMoveTrigger.h"
#include "EventWrapper.h"
namespace reng{
  
PhysicsEngine::PhysicsEngine(){
   queuedEvents = {};
   moveEvent = new Event<SpriteMoveTrigger>("Sprite move event");
   moveEvent->addListener(&testMoveListener);
}
void PhysicsEngine::proccessQueuedEvents(){
    while(!queuedEvents.empty()){
        queuedEvents.front()->notifyListeners();
        queuedEvents.pop();
    }
}
void PhysicsEngine::move(Sprite& sprite,  Vector velocity){
    SpriteMoveTrigger moveTrigger("Sprite moved", sprite, velocity);
    moveEvent->addTrigger(moveTrigger);
    queuedEvents.push(static_cast<EventWrapper*>(moveEvent));
}

bool PhysicsEngine::testMoveListener(SpriteMoveTrigger& trigger){
    std::cout << "Calling test " + trigger.getName() << std::endl;
    std::cout << "At " << trigger.getSprite().getRect().x << std::endl;
    std::cout << "New pos is " << trigger.getNewVeloocity().getX() << std::endl;
    return true;
}

}