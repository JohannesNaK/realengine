#include "CollisionTrigger.h"
#include <iostream>

namespace reng {
    CollisionTrigger::CollisionTrigger(std::string name, Sprite* collider, Sprite* into)
    : EventTrigger(name), collider(collider), into(into) {}
   
   void CollisionTrigger::onPop(){
    if (collider->canBounceFromObjects() && into->isCollidable()){
        Hitbox intoBox = into->getHitBox();
        Hitbox colliderBox = collider->getHitBox();
        Vector collisionCorner(collider->getVelocity().getX() > 0 ? collider->getPosition().getX() + colliderBox.getWidth() : collider->getPosition().getX(), collider->getVelocity().getY() > 0 ? collider->getPosition().getY() + colliderBox.getHeight() : collider->getPosition().getY());
        Vector possibleCornerSameX(collider->getVelocity().getX() > 0 ? collider->getPosition().getX() : collider->getPosition().getX() + colliderBox.getWidth(), collider->getVelocity().getY() > 0 ? collider->getPosition().getY() + colliderBox.getHeight() : collider->getPosition().getY());
        Vector possibleCornerSameY(collider->getVelocity().getX() > 0 ? collider->getPosition().getX() + colliderBox.getWidth() : collider->getPosition().getX(), collider->getVelocity().getY() > 0 ? collider->getPosition().getY() : collider->getPosition().getY() + colliderBox.getHeight());
        Vector newSpeed(collider->getVelocity());
               
        int offset = Vector(intoBox.getWidth() - colliderBox.getWidth(), intoBox.getHeight() - colliderBox.getWidth()).size() + 1;
        //Colliding corners have the same X, with different Y
        if(into->encapsulates(possibleCornerSameX)){
            std::cout << "collision first  if " << std::endl;
            newSpeed.setY(newSpeed.getY()*-1);
        }
        //Colliding corners have the same Y, with different X
        else if(into->encapsulates(possibleCornerSameY)){
            newSpeed.setX(newSpeed.getX()*-1);
            std::cout << "collision second if " << std::endl;
        }
        //Objects collided corner to corner
        else{
            Vector cornerDirection = (collisionCorner - collider->getPosition()).direction();
            
            if(cornerDirection.getX()  < 0)
                newSpeed.setX(newSpeed.getX() > 0 ? newSpeed.getX() * -1 : newSpeed.getX());
            else
                newSpeed.setX(newSpeed.getX() > 0 ? newSpeed.getX(): newSpeed.getX() * -1);

            if(cornerDirection.getY()  < 0)
                newSpeed.setY(newSpeed.getY() > 0 ? newSpeed.getY() * -1: newSpeed.getY());
            else
                newSpeed.setX(newSpeed.getY() > 0 ? newSpeed.getY(): newSpeed.getY() * -1);
 
        }
        collider->addToPosition(newSpeed.direction()*offset);
        collider->setVelocity(newSpeed);
    }
    //addToPosition här?
    }
   Sprite* CollisionTrigger::getColliderSprite(){
    return collider;
   }
   Sprite* CollisionTrigger::getIntoSprite(){
    return into;
   }

}