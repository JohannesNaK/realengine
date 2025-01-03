#ifndef EVENT_TPP
#define EVENT_TPP

#include "Event.h"
#include <iostream>

namespace reng {
    template <typename T>
    Event<T>::Event(const std::string& name) : name(name) {
        listeners = {};
        triggerQueue = {};
    }

    template <typename T>
    void Event<T>::addTrigger(T* trigger) {
        triggerQueue.push(trigger);
    }

    template <typename T>
    void Event<T>::addListener(std::function<void(T&)> listener) {
        listeners.push_back(listener);
    }

    template <typename T>
    void Event<T>::notifyListeners() {
        if (!triggerQueue.empty()) {
            T* trigger = triggerQueue.front();
            
            for (std::function<void(T&)> listener : listeners) {
                listener(*trigger);
      
            }
         trigger->onPop();
         triggerQueue.pop();
         delete trigger;
       }
    }
}

#endif