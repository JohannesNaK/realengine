#include "CollisionTrigger.h"
#include <iostream>

namespace reng {
    CollisionTrigger::CollisionTrigger(std::string name, Sprite* collider, Sprite* into)
    : EventTrigger(name), collider(collider), into(into) {}
   
   void CollisionTrigger::onPop(){
    if (collider->canBounceFromObjects()){
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
           // collider->addToPosition(Vector(0, into->getPosition().getY() - possibleCornerSameX.getY()));
        }
        //Colliding corners have the same Y, with different X
        else if(into->encapsulates(possibleCornerSameY)){
            newSpeed.setX(newSpeed.getX()*-1);
           // collider->addToPosition(Vector(into->getPosition().getX() - possibleCornerSameY.getX(), 0));
            std::cout << "collision second if " << std::endl;
        }
        //Objects collided corner to corner
        else{
           // Vector cornerIndicator = collisionCorner - collider->getPosition();
            //Check what object has the largest hitbox and offset it
            float r = colliderBox.size() > intoBox.size() ? colliderBox.size() : intoBox.size();
            
            
           // Vector offsret = newSpeed.direction()*(-1.2*r);
          //  collider->addToPosition(offset);
           // std::cout << "offset is " << offset.size() << " r is " << r << " speed is " << newSpeed.size() << std::endl;
            newSpeed = newSpeed*-1;
 
        }
        collider->addToPosition(newSpeed.direction()*offset);
        collider->setVelocity(newSpeed);
    }
    //addToPosition här?
    }

}