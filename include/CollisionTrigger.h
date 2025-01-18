#ifndef COLLISIONTRIGGER_H
#define COLLISIONTRIGGER_H
#include "EventTrigger.h"
#include "Sprite.h"
#include <string>
namespace reng {
    class CollisionTrigger : public EventTrigger{
        public:
        CollisionTrigger(std::string name, Sprite* collider, Sprite* into);
        void onPop() override;
        Sprite* getColliderSprite();
        Sprite*  getIntoSprite();
        private:
        Sprite* collider;
        Sprite* into;

    };
};
#endif