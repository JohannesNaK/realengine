#include "KeyboardTrigger.h"
#include <string>

namespace reng  {
    KeyboardTrigger::KeyboardTrigger(const std::string& name, KeyState state, char key) : EventTrigger(name),state(state), key(key){

    }
    const char KeyboardTrigger::getKey(){
        return key;
    }
    const KeyboardTrigger::KeyState KeyboardTrigger::getKeyState(){
        return state;
    }
    void KeyboardTrigger::onPop(){
        
    }
}