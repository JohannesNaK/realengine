#ifndef EventTrigger_H
#define EventTrigger_H
#include <string>
namespace reng{
    class EventTrigger{
        public:
        EventTrigger(const std::string name);
        const std::string getName();
        private:
        const std::string name;

    };
};
#endif