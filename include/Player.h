#ifndef PLAYER_H
#define PLAYER_H
#include "Sprite.h"
#include "Event.h"
#include "KeyboardTrigger.h"
#include "Vector.h"
#include <string>
namespace reng {
    class Player : public Sprite {
        public:
        Player(const std::string& name, int x, int y, int w, int h);
        void move();
        void tick() override;
        private:
        void onW(KeyboardTrigger& keyTrigger);
        void onA(KeyboardTrigger& keyTrigger);
        void onS(KeyboardTrigger& keyTrigger);
        void onD(KeyboardTrigger& keyTrigger);
        static Event<KeyboardTrigger> keys;
        const std::string& name;
    };
};
#endif