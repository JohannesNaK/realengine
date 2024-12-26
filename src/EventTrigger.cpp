#include "EventTrigger.h"
#include <string>
namespace reng
{
    EventTrigger::EventTrigger(const std::string name) : name(name) {

    }
    
    const std::string EventTrigger::getName(){
        return name;
    }
}  
