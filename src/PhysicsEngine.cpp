#include "PhysicsEngine.h"
#include "GameEngine.h"
#include "Vector.h"
#include "Sprite.h"
#include "SpriteMoveTrigger.h"
#include "EventWrapper.h"
#include <vector>
#include <functional>
namespace reng{
  
PhysicsEngine::PhysicsEngine(){
   moveEvent = new Event<SpriteMoveTrigger>("Sprite move event");
 
}
void PhysicsEngine::addMoveListener(std::function<void(SpriteMoveTrigger&)> listener){
    moveEvent->addListener(listener);
}
void PhysicsEngine::move(Sprite& sprite,  Vector velocity){

    Vector oldPosition =  sprite.getPosition();
    SpriteMoveTrigger* moveTrigger = new SpriteMoveTrigger("Sprite moved",sprite, oldPosition, velocity);
    moveEvent->addTrigger(moveTrigger);
    GameEngine::getInstance()->addEventToQueue(moveEvent);
}

 

}