#include "PhysicsEngine.h"
#include "GameEngine.h"
#include "Vector.h"
#include "Sprite.h"
#include "SpriteMoveTrigger.h"
#include "EventWrapper.h"
namespace reng{
  
PhysicsEngine::PhysicsEngine(){
   moveEvent = new Event<SpriteMoveTrigger>("Sprite move event");
   moveEvent->addListener(&testMoveListener);
}
 
void PhysicsEngine::move(Sprite& sprite,  Vector velocity){

    std::cout << "at move req" << std::endl;
    Vector oldPosition =  sprite.getPosition();
    sprite.setPosition(velocity);
    SpriteMoveTrigger moveTrigger("Sprite moved",sprite, oldPosition, velocity);
    moveEvent->addTrigger(moveTrigger);
    GameEngine::getInstance()->addEventToQueue(moveEvent);
}

void PhysicsEngine::testMoveListener(SpriteMoveTrigger& trigger){
    std::cout << "Calling test " + trigger.getName() << std::endl;
    std::cout << "New velocity is" << trigger.getNewVeloocity().getX() << std::endl;
}

}