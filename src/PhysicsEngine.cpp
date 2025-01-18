#include "PhysicsEngine.h"
#include "GameEngine.h"
 

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
    Vector newPosition = oldPosition + velocity;

    if (enforcaBoundaries) {
        //Get window size
        int windowWidth = gameEngine->getWindowWidth();
        int windowHeight = gameEngine->getWindowHeight();
            
        //Adjust position X
        if(newPosition.getX() < 0) {
            newPosition.setX(0);
            if(sprite.canBounceFromBoundary()) {
                velocity.setX(-velocity.getX()); //Bounce back
            } else {
                velocity.setX(0);   //Can't bounce
            }
            
        } else if (newPosition.getX() + sprite.getWidth() > windowWidth) {
            newPosition.setX(windowWidth - sprite.getWidth());
            if(sprite.canBounceFromBoundary()) {
                velocity.setX(-velocity.getX()); //Bounce back
            } else {       //Can't bounce
                velocity.setX(0);
            }
        }

        //Adjust position Y
        if (newPosition.getY() < 0) {
            newPosition.setY(0);
            if(sprite.canBounceFromBoundary()) {
                velocity.setY(-velocity.getY());  // Bounce back
            } else {
                velocity.setY(0);
            }
        } else if (newPosition.getY() + sprite.getHeight() > windowHeight) {
            newPosition.setY(windowHeight - sprite.getHeight());
            if(sprite.canBounceFromBoundary()) {
                velocity.setY(-velocity.getY());  // Bounce back
            } else {
                velocity.setY(0);
            }
        }
    }
    
    //Update sprite's position
    sprite.setPosition(newPosition);
    sprite.setVelocity(velocity);

    //Trigger move event
    SpriteMoveTrigger* moveTrigger = new SpriteMoveTrigger("Sprite moved",sprite, oldPosition, velocity);
    moveEvent->addTrigger(moveTrigger);
    gameEngine->addEventToQueue(moveEvent);
}
void PhysicsEngine::collisionListener(Sprite& source) {
  
    for (Sprite* sprite : gameEngine->getSprites()){
        if (sprite != &source){
            Vector sPos = sprite->getPosition();
            Vector sBottom = sPos + Vector(sprite->getHitBox().getWidth(), -sprite->getHitBox().getHeight());
            Vector sourcePos = source.getPosition();
            Vector sourceBottom = sourcePos + Vector(source.getHitBox().getWidth(), -source.getHitBox().getHeight());
           if( checkCollision(sPos, sBottom, sourcePos, sourceBottom) || checkCollision(sourcePos, sourceBottom, sPos, sBottom)){
           CollisionTrigger* collision = new CollisionTrigger("Collision trigger", &source, sprite);
            collisionEvent->addTrigger(collision);
            gameEngine->addEventToQueue(collisionEvent);
      
            break;
           }

        }
    }
     
}
bool PhysicsEngine::checkCollision(Vector sPos, Vector sBottom, Vector sourcePos, Vector sourceBottom) {
    if (sPos.getX() >= sourcePos.getX() && sPos.getX() <= sourceBottom.getX()){
                if (sPos.getY() <= sourcePos.getY() && sPos.getY() >= sourceBottom.getY()){
                     
                        //std::cout << "checked 1 " << std::endl;
                     return true;
                } else if (sBottom.getY() <= sourcePos.getY() && sBottom.getY() >= sourceBottom.getY()) {
                   
                         //std::cout << "checked 1 " << std::endl;
                     return true;
                }
    } else  if (sBottom.getX() >= sourcePos.getX() && sBottom.getX() <= sourceBottom.getX()){
                 if (sPos.getY() <= sourcePos.getY() && sPos.getY() >= sourceBottom.getY()){
                    //std::cout << "checked 1 " << std::endl;
                    return true;
                } else if (sBottom.getY() <= sourcePos.getY() && sBottom.getY() >= sourceBottom.getY()) {
                     //std::cout << "checked 1 " << std::endl;
                     return true;
                      
                }
    }
    return false;
}

    void PhysicsEngine::enableBoundaries(bool enable) {
        enforcaBoundaries = enable;
    }
}