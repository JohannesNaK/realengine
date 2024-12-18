#include "SpriteMove.h"
#include "Sprite.h"
#include "Vector.h"
#include <iostream>
namespace reng
{
    SpriteMove::SpriteMove(Sprite& sprite, Vector velocity) : sprite(sprite), velocity(velocity){
            std::cout << "initalized sprite move" << std::endl;
    }
    Sprite& SpriteMove::getSprite(){
        return sprite;
    }
    Vector& SpriteMove::getVelocity(){
        return velocity;
    }
    bool SpriteMove::cancel(){
    
        return true;
    }
} 
