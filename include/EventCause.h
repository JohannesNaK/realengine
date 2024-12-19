#ifndef EVENTCAUSE_H
#define EVENTCAUSE_H
#include <string>
namespace reng{
    class EventCause{
        public:
        EventCause(const std::string& name);
        const std::string& getName();
        private:
        const std::string& name;

    };
};
#endif