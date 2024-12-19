#include "SpriteMoveTrigger.h"

namespace reng {
        SpriteMoveTrigger::SpriteMoveTrigger(const std::string& name, Sprite& sprite, Vector velocity) : EventCause(name),sprite(sprite), velocity(velocity){

        }
        Sprite& SpriteMoveTrigger::getSprite(){
            return sprite;
        }
       Vector SpriteMoveTrigger::getNewVeloocity(){ 
        return velocity;
       } 
}