#include "SpriteMoveTrigger.h"
#include <iostream>
namespace reng {
    
        SpriteMoveTrigger::SpriteMoveTrigger(const std::string& name, Sprite& sprite, Vector oldPosition, Vector newVelocity) : 
 
        EventTrigger(name),sprite(sprite),oldPosition(oldPosition), newVelocity(newVelocity){

        }
        void SpriteMoveTrigger::onPop(){
          sprite.addToPosition(newVelocity);
          sprite.setVelocity(newVelocity);
          std::cout << "set velocity to " << newVelocity.getY() << std::endl;
        }
        void SpriteMoveTrigger::setVelocity(Vector velocity){
          newVelocity = velocity;
        }
        Sprite& SpriteMoveTrigger::getSprite(){
            return sprite;
        }
       Vector SpriteMoveTrigger::getNewVeloocity(){ 
        return newVelocity;
       }
       Vector SpriteMoveTrigger::getNewPosition(){
        return oldPosition + newVelocity;
       }
          Vector SpriteMoveTrigger::getOldPosition(){ 
        return oldPosition;
       } 
}