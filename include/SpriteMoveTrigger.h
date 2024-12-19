#ifndef SPRITEMOVETRIGGER_h
#define SPRITEMOVETRIGGER_h
#include "EventCause.h"
#include <string>
#include "Sprite.h"
#include "Vector.h"
namespace reng
{
  class SpriteMoveTrigger: public EventCause {
        
        public:
        SpriteMoveTrigger(const std::string& name, Sprite& sprite, Vector velocity);
        Sprite& getSprite();
        Vector getNewVeloocity();
        private:
        Sprite& sprite;
         Vector velocity;
  };    
};
#endif
