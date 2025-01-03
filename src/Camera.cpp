#include "Camera.h"
#include "Sprite.h"
#include "Vector.h"
#include "GameEngine.h"
#include <SDL2/SDL.h>
namespace reng {
    Camera::Camera(SDL_Renderer* renderer,  Sprite* sprite) 
    :  sprite(sprite), orgin(Vector(0,0)),renderer(renderer){
        //Initialize camera's sprite lock-on.
        if (sprite == nullptr){
            orgin = Vector(0,0);
        } else {
        orgin = sprite->getPosition();
        state = true;
        }
            
        GameEngine::getInstance()->getPhysicsEngine()->addMoveListener([this](SpriteMoveTrigger& trigger){
            //Has the locked sprite moved? If so, change the relative positions.
        if (&trigger.getSprite() == this->sprite && this->sprite != nullptr){
           Vector position = trigger.getNewPosition();
           Vector orginOffset =  trigger.getNewVeloocity();
           //If player is at the top or bottom,prevent the sprite from moving.
           //Instead, move every other sprite in the opposite direction of the camera's velocity.
           if (position.getY()- 150 <= 0 && trigger.getNewVeloocity().getY() < 0) {
               trigger.setVelocity(Vector(trigger.getNewVeloocity().getX(), 0));
           } else if (position.getY()+150 >=600 && trigger.getNewVeloocity().getY() > 0){
                       trigger.setVelocity(Vector(trigger.getNewVeloocity().getX(), 0));
           }
             //If player is at the right edge or left edge,prevent the sprite from moving.
           //Instead, move every other sprite in the opposite direction of the camera's velocity.
            if (position.getX()- 150 <= 0 && trigger.getNewVeloocity().getX() < 0) {
                  trigger.setVelocity(Vector(0, trigger.getNewVeloocity().getY()));
           } else if (position.getY()+150 >=600 && trigger.getNewVeloocity().getY() > 0){
                  trigger.setVelocity(Vector(0, trigger.getNewVeloocity().getY()));
           }
            this->setOrgin(orginOffset);
               this->setUpdate(true);
             }
        }); 
    }
    bool Camera::update(){
        return state;
    }
    void Camera::setUpdate(bool newState){
            state = newState;
    }
      Sprite* Camera::getSprite() {
        return sprite;
    }
    void Camera::setSprite(Sprite* newSprite){
        sprite = newSprite;
    }
    Vector Camera::getOrgin(){
        return orgin;
    }
    void Camera::setOrgin(Vector newOrgin){
        orgin = newOrgin;
    }
 

     
}