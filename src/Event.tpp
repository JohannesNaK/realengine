#ifndef EVENT_TPP
#define EVENT_TPP

#include "Event.h"
#include <iostream>

 
namespace reng {

    template <typename Cause>
    Event<Cause>::Event(const std::string& name, std::vector<Cause> causes, std::vector<bool (*)(Cause&)> listenerFuncs)
        : name(name), causes(causes), listenerFuncs(listenerFuncs){}

template <typename Cause>
void Event<Cause>::addListener(bool (*execute)(Cause& cause)) {
    if (execute != nullptr)
        listenerFuncs.push_back(execute);
}

template <typename Cause>
void Event<Cause>::addCause(Cause cause) {
    std::cout << "Adding cause of type: " << typeid(Cause).name() << std::endl;
    std::cout << "Cause address: " << &cause << std::endl;
    std::cout << "try with vec " << std::endl;
    std::vector<Cause> causses;
    causes.push_back(cause);
}

    template <typename Cause>
    void Event<Cause>::notifyListeners() {
        std::cout << "in listener" << std::endl;
        if (!(causes.empty())){
            std::cout << "not empty";
            for (auto f : listenerFuncs){
                
                f(causes.at(0));
            }
       
        }   else {
            std::cout << "causes is empty!";
        }
     
    }

    template <typename Cause>
    const std::string& Event<Cause>::getName() const {
        return name;
    }

}  

#endif