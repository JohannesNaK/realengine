#ifndef EVENTCAUSE_H
#define EVENTCAUSE_H
namespace reng {
    class EventCause{
            public:
             virtual ~EventCause();
            virtual bool cancel() = 0;
    };
};
#endif