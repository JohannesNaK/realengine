#ifndef EVENTWRAPPER_H
#define EVENTWRAPPER_H
namespace reng {
    class EventWrapper{
        public:
        virtual void notifyListeners() = 0;
    
    };
};
#endif