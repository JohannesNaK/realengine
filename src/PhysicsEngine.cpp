#include "PhysicsEngine.h"
#include "GameEngine.h"
#include "Vector.h"
#include "Sprite.h"
#include <iostream>
#include "Event.h"
#include "SpriteMove.h"
#include <memory>
#include "RectSprite.h"
namespace reng{
  
PhysicsEngine::PhysicsEngine(GameEngine* eng){
    gameEngine = eng;
    
     
    
 
}
void PhysicsEngine::moveRequest(Sprite& sprite, Vector velocity) {
    std::cout << "Calling moveRequest" << std::endl;
    try {
 
        SpriteMove move(sprite, velocity);  // Potential memory allocation here
        std::cout << "SpriteMove initialized" << std::endl;
        std::cout << "why";
        if (ev == nullptr) {
            std::cout << "ev is nullptr" << std::endl;
        } else {
            ev->addCause(move);  // This may also cause memory allocation issues
            std::cout << "Cause added to event" << std::endl;
        }
    } catch (const std::bad_alloc& e) {
        std::cout << "Caught bad_alloc: " << e.what() << std::endl;
         // Rethrow the exception to terminate the program
    }
}
void PhysicsEngine::pollEvents(){
    
}
void PhysicsEngine::setMoveEvent(Event<SpriteMove>* evs){
    ev = evs;
}
 bool PhysicsEngine::addSprite(Sprite* sprite){
    
    return true;
}

}