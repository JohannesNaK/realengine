#include "Sprite.h"
#include <SDL2/SDL.h>
#include "Vector.h"
#include <iostream>
#include "GameEngine.h"

namespace reng{
    Sprite::Sprite(int x, int y, int w, int h):  position(Vector(x,y)), velocity(Vector(0,0)),rect{x, y, w, h}, texture(nullptr) {
      std::cout << "position is " << position.getX() << std::endl;
      std::cout << "velocity is " << velocity.getX() << std::endl;
    }
    Sprite::~Sprite(){}

    void Sprite::draw(SDL_Renderer* renderer){
        if(texture)
            SDL_RenderCopy(renderer, texture, NULL, &getRect());
    }
    void Sprite::addToPosition(Vector otherPosition){
        position = position + otherPosition;
        std::cout << "New position is " << position.getX() << ":" << position.getY() << std::endl;
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
    Vector Sprite::getPosition(){
        return position;
    }
    Vector Sprite::getVelocity(){
        return velocity;
    }
    void Sprite::setTexture(SDL_Texture* tx){
        texture = tx;
    }
}