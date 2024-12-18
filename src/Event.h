#ifndef EVENT_H
#define EVENT_H
#include <string>
#include <queue>
#include <vector>
#include <functional>

 
namespace reng {

    template <typename Cause>
    class Event {
    public:
        Event(const std::string& name, std::vector<Cause> causes, std::vector<bool (*)(Cause&)> listenerFuncs);
        void addListener(bool (*executeFunc)(Cause& cause));
        void addCause( Cause cause);
        void notifyListeners();
        const std::string& getName() const;
    private:
        const std::string name; 
        std::vector<Cause> causes;                           
       std::vector<bool (*)(Cause&)> listenerFuncs;                      
    }; 

} 

 #include "Event.tpp" 
#endif