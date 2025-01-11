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
        Player(const std::string  name, int x, int y, int w, int h, int hp, char up, char down, char left, char right);
        virtual void tick() override;
        void setUpKey();
        void setDownKey();
        void setLeftKey();
        void setRightKey();
        private:
        char up,down,left,right;
        void onUp(KeyboardTrigger& keyTrigger);
        void onDown(KeyboardTrigger& keyTrigger);
        void onLeft(KeyboardTrigger& keyTrigger);
        void onRight(KeyboardTrigger& keyTrigger);
        static Event<KeyboardTrigger> keys;
        
    };
};
#endif