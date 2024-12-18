#ifndef SPRITEMOVE_H
#define SPRITEMOVE_H
#include "EventCause.h"
#include "Sprite.h"
#include "Vector.h"
namespace reng {
    class SpriteMove : public EventCause  {
        public:
        SpriteMove(Sprite& sprite, Vector velocity);
        Sprite& getSprite();
        Vector& getVelocity();
        bool cancel() override;
        private:
        Sprite& sprite;
        Vector velocity;
    };
    
};
#endif