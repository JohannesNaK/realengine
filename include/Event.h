#ifndef EVENT_H
#define EVENT_H
#include "EventWrapper.h"
#include <queue>
#include <vector>
#include <string>
namespace reng {
    template <typename T>
    class Event : public EventWrapper{
    public:
        Event(const std::string& name);
        void addTrigger(T trigger);
        void addListener(bool(*listener)(T& test));
        void notifyListeners() override;

    private:
        std::string name; // Changed to non-reference
        std::vector<bool(*)(T& test)> listeners;
        std::queue<T> triggerQueue;
    };
}

#include "../src/Event.tpp" 
#endif