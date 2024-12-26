#ifndef EVENT_H
#define EVENT_H
#include "EventWrapper.h"
#include <queue>
#include <vector>
#include <string>
#include <functional>
namespace reng {
    template <typename T>
    class Event : public EventWrapper{
    public:
        Event(const std::string& name);
        void addTrigger(T trigger);
        void addListener(std::function<void(T&)> test);
        void notifyListeners() override;

    private:
        std::string name; 
        std::vector<std::function<void(T&)>>listeners;
        std::queue<T> triggerQueue;
    };
}

#include "../src/Event.tpp" 
#endif