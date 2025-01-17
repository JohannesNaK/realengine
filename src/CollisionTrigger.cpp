#include "CollisionTrigger.h"

namespace reng {
    CollisionTrigger::CollisionTrigger(std::string name, Sprite* collider, Sprite* into)
    : EventTrigger(name),knockBack(true), collider(collider), into(into) {}
   
   void CollisionTrigger::setKnockback(bool knock){
    knockBack = knock;
   }
   void CollisionTrigger::onPop(){
    if (knockBack){
        Hitbox intoBox = into->getHitBox();
        Hitbox colliderBox = collider->getHitBox();
        int offset = Vector(intoBox.getWidth() - colliderBox.getWidth(), intoBox.getHeight() - colliderBox.getWidth()).size() + 1;
        
        collider->addToPosition(collider->getVelocity().direction()*(-offset));
        //    ^
        //  ^
        collider->setVelocity(collider->getVelocity()*-1);
       
    }
    }

}