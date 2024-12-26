#ifndef SPRITEMOVETRIGGER_h
#define SPRITEMOVETRIGGER_h
#include "EventTrigger.h"
#include <string>
#include "Sprite.h"
#include "Vector.h"
namespace reng
{
  class SpriteMoveTrigger: public EventTrigger {
        
        public:
        SpriteMoveTrigger(const std::string& name, Sprite& sprite,Vector oldVelocity, Vector newVelocity);
        Sprite& getSprite();
        Vector getOldVelocity();
        Vector getNewVeloocity();
        private:
        Sprite& sprite;
        Vector oldVelocity;
        Vector newVelocity;
  };    
};
#endif
