#ifndef EventTrigger_H
#define EventTrigger_H
#include <string>
#include <iostream>
namespace reng{
    class EventTrigger{
        public:
        EventTrigger(const std::string name);
        virtual ~EventTrigger() {}
        virtual void onPop() = 0;
        const std::string getName();

        private:
        const std::string name;

    };
};
#endif