#include "EventCause.h"
#include <string>
namespace reng
{
    EventCause::EventCause(const std::string& name) : name(name) {

    }
    
    const std::string& EventCause::getName(){
        return name;
    }
}  
