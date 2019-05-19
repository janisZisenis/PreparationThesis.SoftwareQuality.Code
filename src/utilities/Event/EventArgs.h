#ifndef UTILITIES_EVENTARGS_H
#define UTILITIES_EVENTARGS_H

#include <memory>
#include <string>
using namespace std;

class EventArgs;
typedef shared_ptr<EventArgs> EventArgsPtr;
class EventArgs {
public:
    static EventArgsPtr getNewInstance(){
        return EventArgsPtr(new EventArgs());
    }
    virtual ~EventArgs() {}
protected:
    EventArgs() {}
};


#endif //UTILITIES_EVENTARGS_H