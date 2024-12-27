#ifndef KEYBOARDTRIGGER_H
#define KEYBOARDTRIGGER_H
#include "EventTrigger.h"
#include <string>
namespace reng {
    class KeyboardTrigger : public EventTrigger {
        public:
        enum class KeyState { PRESSED, RELEASED };
        KeyboardTrigger(const std::string& name, KeyState state, const char key);
        const char getKey();
        void onPop() override;
       const KeyState getKeyState();
        private:
        KeyState state;
        const char key;
 
    };
};
#endif