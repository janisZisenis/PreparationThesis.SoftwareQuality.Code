#ifndef UTILITIES_EVENTARGSMOCKS_H
#define UTILITIES_EVENTARGSMOCKS_H

#include "EventArgs.h"

class EventArgsDummy;
typedef shared_ptr<EventArgsDummy> EventArgsDummyPtr;
class EventArgsDummy : public EventArgs {
public:
    static EventArgsDummyPtr getNewInstance(){
        return EventArgsDummyPtr(new EventArgsDummy());
    }
    virtual ~EventArgsDummy() {}
protected:
    EventArgsDummy() : EventArgs() {}
};

#endif //UTILITIES_EVENTARGSMOCKS_H