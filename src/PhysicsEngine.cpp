#include "PhysicsEngine.h"
#include "GameEngine.h"
#include "Vector.h"
#include "Sprite.h"
#include "SpriteMoveTrigger.h"
#include "EventWrapper.h"
#include <vector>
#include <functional>

namespace reng {
 
PhysicsEngine::PhysicsEngine(GameEngine* gameEngine) : gameEngine(gameEngine){
   moveEvent = new Event<SpriteMoveTrigger>("Sprite move event");
    collisionEvent = new Event<CollisionTrigger>("Collision event");  
   moveEvent->addListener([this](SpriteMoveTrigger& trigger) {
            collisionListener(trigger.getSprite());
    });
 
}
void PhysicsEngine::addMoveListener(std::function<void(SpriteMoveTrigger&)> listener){
    moveEvent->addListener(listener);
}
void PhysicsEngine::addCollisionListener(std::function<void(CollisionTrigger&)> listener){
    collisionEvent->addListener(listener);
}
 void PhysicsEngine::move(Sprite& sprite,  Vector velocity){
    Vector oldPosition =  sprite.getPosition();
    SpriteMoveTrigger* moveTrigger = new SpriteMoveTrigger("Sprite moved",sprite, oldPosition, velocity);
    moveEvent->addTrigger(moveTrigger);
    gameEngine->addEventToQueue(moveEvent);
}
void PhysicsEngine::collisionListener(Sprite& source) {
  
    for (Sprite* sprite : gameEngine->getSprites()){
        if (sprite != &source){
            Vector sPos = sprite->getPosition();
            Vector sBottom = sPos + Vector(sprite->getRect().w, sprite->getRect().h);
            Vector sourcePos = source.getPosition();
            Vector sourceBottom = sourcePos + Vector(source.getRect().w, source.getRect().h);
           if( checkCollision(sPos, sBottom, sourcePos, sourceBottom) || checkCollision(sourcePos, sourceBottom, sPos, sBottom)){
           CollisionTrigger* collision = new CollisionTrigger("Collision trigger", source, *sprite);
            collision->setKnockback(true);
            collisionEvent->addTrigger(collision);
            gameEngine->addEventToQueue(collisionEvent);
            break;
           }

        }
    }
     
}
bool PhysicsEngine::checkCollision(Vector sPos, Vector sBottom, Vector sourcePos, Vector sourceBottom) {
    if (sPos.getX() >= sourcePos.getX() && sPos.getX() <= sourceBottom.getX()){
                if (sPos.getY() <= sourcePos.getY() && sPos.getY() >= sourcePos.getY()){
                     
                        //std::cout << "checked 1 " << std::endl;
                     return true;
                } else if (sBottom.getY() <= sourcePos.getY() && sBottom.getY() >= sourcePos.getY()) {
                   
                         //std::cout << "checked 1 " << std::endl;
                     return true;
                }
    } else  if (sBottom.getX() >= sourcePos.getX() && sBottom.getX() <= sourceBottom.getX()){
                 if (sPos.getY() <= sourcePos.getY() && sPos.getY() >= sourcePos.getY()){
                    //std::cout << "checked 1 " << std::endl;
                    return true;
                } else if (sBottom.getY() <= sourcePos.getY() && sBottom.getY() >= sourcePos.getY()) {
                     //std::cout << "checked 1 " << std::endl;
                     return true;
                      
                }
    }
    return false;
}

}