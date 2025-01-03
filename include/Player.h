#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"
#include "Event.h"
#include "KeyboardTrigger.h"
#include "Vector.h"
#include <string>

namespace reng {
    class Player : public Entity {
        public:
        Player(const std::string  name, int x, int y, int w, int h, int hp);
    
        virtual void tick() override;
        private:
        void onW(KeyboardTrigger& keyTrigger);
        void onA(KeyboardTrigger& keyTrigger);
        void onS(KeyboardTrigger& keyTrigger);
        void onD(KeyboardTrigger& keyTrigger);
        static Event<KeyboardTrigger> keys;
        
    };
};
#endif