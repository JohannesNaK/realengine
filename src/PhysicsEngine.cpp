#include "PhysicsEngine.h"
#include "GameEngine.h"
#include "Vector.h"
#include "Sprite.h"
namespace reng{
  

void PhysicsEngine::move(Sprite* sprite,  Vector velocity){
    SDL_Rect rect = *sprite->getRect();
    rect.x+=velocity.getX();
    rect.y+= velocity.getY();
}
 bool PhysicsEngine::addSprite(Sprite* sprite){
   
    return true;
}

}