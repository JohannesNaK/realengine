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
        SpriteMoveTrigger(const std::string& name, Sprite& sprite,Vector oldPosition, Vector newVelocity);
        Sprite& getSprite();
        Vector getNewPosition();
        Vector getOldPosition();
        Vector getNewVeloocity();
        void setVelocity(Vector velocity);
        void onPop() override;
        private:
        Sprite& sprite;
        Vector oldPosition;
        Vector newVelocity;
  };    
};
#endif
