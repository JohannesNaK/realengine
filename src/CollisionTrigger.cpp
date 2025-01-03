#include "CollisionTrigger.h"

namespace reng {
    CollisionTrigger::CollisionTrigger(std::string name, Sprite& collider, Sprite& into)
    : EventTrigger(name),knockBack(true), collider(collider), into(into) {}
   
   void CollisionTrigger::setKnockback(bool knock){
    knockBack = knock;
   }
   void CollisionTrigger::onPop(){
    if (knockBack){
        std::cout << "called pop" << std::endl;
       
    }
    }

}