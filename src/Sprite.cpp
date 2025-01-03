#include "Sprite.h"
#include <SDL2/SDL.h>
#include "Vector.h"
#include <iostream>
#include "GameEngine.h"

namespace reng{
    Sprite::Sprite(int x, int y, int w, int h, std::string id):  position(Vector(x,y)), velocity(Vector(0,0)), id(id),rect{x, y, w, h}
    ,texture(nullptr) {
         
    }
    Sprite::~Sprite(){}

    void Sprite::draw(SDL_Renderer* renderer){
        if(texture)
            SDL_RenderCopy(renderer, texture, NULL, &getRect());
    }
    void Sprite::addToPosition(Vector otherPosition){
        position = position + otherPosition;
        rect.x = position.getX();
        rect.y = position.getY();
    }
    void Sprite::setPosition(Vector newPosition){
        position = newPosition;
        rect.x = position.getX();
        rect.y = position.getY();
    }
     void Sprite::setVelocity(Vector newVelocity){
        velocity = newVelocity;
    }
    Vector Sprite::getPosition() const{
        return position;
    }
    Vector Sprite::getVelocity() const{
        return velocity;
    }
    
    void Sprite::setTexture(SDL_Texture* tx){
        texture = tx;
    }
}