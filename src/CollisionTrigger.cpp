#include "CollisionTrigger.h"

namespace reng {
    CollisionTrigger::CollisionTrigger(std::string name, Sprite* collider, Sprite* into)
    : EventTrigger(name),knockBack(false), collider(collider), into(into) {}
   
   void CollisionTrigger::setKnockback(bool knock){
    knockBack = knock;
   }
   void CollisionTrigger::onPop(){
    if (knockBack){
        Hitbox intoBox = into->getHitBox();
        Hitbox colliderBox = collider->getHitBox();
        int offset = Vector(intoBox.getWidth() - colliderBox.getWidth(), intoBox.getHeight() - colliderBox.getWidth()).size() + 1;
        //Vector collisionCorner(collider->getVelocity().getX() > 0 ? colliderBox.getWidth() : collider->getPosition().getX(), collider->getVelocity().getY() > 0 ? colliderBox.getHeight() : collider->getPosition().getY());
        Vector possibleCornerSameX(collider->getVelocity().getX() > 0 ? collider->getPosition().getX() : colliderBox.getWidth(), collider->getVelocity().getY() > 0 ? colliderBox.getHeight() : collider->getPosition().getY());
        Vector possibleCornerSameY(collider->getVelocity().getX() > 0 ? colliderBox.getWidth() : collider->getPosition().getX(), collider->getVelocity().getY() > 0 ? collider->getPosition().getY() : colliderBox.getHeight());
        Vector newSpeed(collider->getVelocity());

        if(into->encapsulates(possibleCornerSameX))
            newSpeed.setY(newSpeed.getY()*-1);
        else if(into->encapsulates(possibleCornerSameY))
            newSpeed.setX(newSpeed.getX()*-1);
        else
            newSpeed * -1;

        collider->addToPosition(collider->getVelocity().direction()*(-offset));
        //    ^
        //  ^
        collider->setVelocity(newSpeed);
       
    }
    }

}