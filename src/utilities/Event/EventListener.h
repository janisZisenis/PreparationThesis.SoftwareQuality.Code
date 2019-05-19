#ifndef UTILITIES_EVENTLISTENER_H
#define UTILITIES_EVENTLISTENER_H

#include "utilities/Object/Object.h"

template <class T> class EventListener;
template <class T> using EventListenerPtr = std::shared_ptr < EventListener<T> >;
template <class T> class EventListener {
public:
    virtual ~EventListener<T>() {}
protected:
    EventListener<T>(){}

public:
	virtual void handleEvent(ObjectPtr sender, std::shared_ptr<T> args) = 0;
};


#endif //UTILITIES_EVENTLISTENER_H