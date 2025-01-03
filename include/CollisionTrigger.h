#ifndef COLLISIONTRIGGER_H
#define COLLISIONTRIGGER_H
#include "EventTrigger.h"
#include "Sprite.h"
#include <string>
namespace reng {
    class CollisionTrigger : public EventTrigger{
        public:
        CollisionTrigger(std::string name, Sprite& collider, Sprite& into);
        void onPop() override;
        void setKnockback(bool knock);
        Sprite& getColliderSprite();
        Sprite& getIntoSprite();
        private:
        bool knockBack;
        Sprite& collider;
        Sprite& into;

    };
};
#endif