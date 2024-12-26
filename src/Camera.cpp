#include "Camera.h"
#include "Sprite.h"
#include "Vector.h"
#include "GameEngine.h"
#include <SDL2/SDL.h>
namespace reng {
    Camera::Camera(SDL_Renderer* renderer,  Sprite* sprite) 
    :  sprite(sprite), orgin(Vector(0,0)),renderer(renderer){
        if (sprite == nullptr){
            orgin = Vector(0,0);
        } else {
        orgin = sprite->getPosition();
        state = true;
        }
            
        GameEngine::getInstance()->getPhysicsEngine()->addMoveListener([this](SpriteMoveTrigger& trigger){
            //Has the locked sprite moved? If so, change the relative positions.
            if (&trigger.getSprite() == this->sprite){
               this->setOrgin(this->getSprite()->getPosition() -trigger.getOldVelocity());
               this->setUpdate(true);
               std::cout << "Updating pos to " << this->getOrgin().getX() << ":" << this->getOrgin().getY() << std::endl;
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