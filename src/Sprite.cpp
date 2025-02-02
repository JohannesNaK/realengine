#include "Sprite.h"
#include <SDL2/SDL.h>
#include "Vector.h"
#include <iostream>
#include "GameEngine.h"

namespace reng{
    Sprite::Sprite(int x, int y, int w, int h):  position(Vector(x,y)), velocity(Vector(0,0)), rect{x, y, w, h}
    ,texture(nullptr), hitBox(w+10,h+10), bounceObjects(false), bounceBoundary(false), collidable(true){
         
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
    Hitbox Sprite::getHitBox() const{
        return hitBox;
    }
    Vector Sprite::getPosition() const{
        return position;
    }
    Vector Sprite::getVelocity() const{
        return velocity;
    }
    
    void Sprite::setTexture(std::string txName){
        texture = GameEngine::getInstance()->getResourceHandler()->getTexture(txName);
    }

    int Sprite::getHeight() const{
        return rect.h;
    }

    int Sprite::getWidth() const{
        return rect.w;
    }

    bool Sprite::encapsulates(Vector point){
        if(point.getX() > position.getX() && point.getX() < position.getX() + hitBox.getWidth() && point.getY() > position.getY() && point.getY() < position.getY() + hitBox.getHeight())
            return true;
        return false;
    }
}