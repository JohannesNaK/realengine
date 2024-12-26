#include "SpriteMoveTrigger.h"

namespace reng {
    
        SpriteMoveTrigger::SpriteMoveTrigger(const std::string& name, Sprite& sprite, Vector oldVelocity, Vector newVelocity) : 
 
        EventTrigger(name),sprite(sprite),oldVelocity(oldVelocity), newVelocity(newVelocity){

        }
        Sprite& SpriteMoveTrigger::getSprite(){
            return sprite;
        }
       Vector SpriteMoveTrigger::getNewVeloocity(){ 
        return newVelocity;
       } 
          Vector SpriteMoveTrigger::getOldVelocity(){ 
        return oldVelocity;
       } 
}