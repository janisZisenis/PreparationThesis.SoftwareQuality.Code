#ifndef UTILITIES_EVENTLISTENER_MOCKS_H
#define UTILITIES_EVENTLISTENER_MOCKS_H

#include "EventListener.h"

template <class T> class EventListenerDummy;
template <class T> using EventListenerDummyPtr = shared_ptr < EventListenerDummy<T> >;
template <class T> class EventListenerDummy : public EventListener<T> {
public:
    static EventListenerDummyPtr<T> getNewInstance(){
        return EventListenerDummyPtr<T>(new EventListenerDummy<T>());
    }
    virtual ~EventListenerDummy<T>() {}
protected:
    EventListenerDummy<T>() : EventListener<T>() {}
public:
	virtual void handleEvent(ObjectPtr sender, shared_ptr<T> args) {}
};

template <class T> class EventListenerSpy;
template <class T> using EventListenerSpyPtr = shared_ptr < EventListenerSpy<T> >;
template <class T> class EventListenerSpy : public EventListenerDummy<T> {
public:
    static EventListenerSpyPtr<T> getNewInstance(){
        return EventListenerSpyPtr<T>(new EventListenerSpy<T>());
    }
    virtual ~EventListenerSpy<T>() {}
protected:
    EventListenerSpy<T>() : EventListenerDummy<T>() {}
private:
	ObjectPtr receivedObject;
	shared_ptr<T> receivedArgs;
	int timesTriggered = 0;
public:
	virtual void handleEvent(ObjectPtr sender, shared_ptr<T> args) {
		this->receivedObject = sender;
		this->receivedArgs = args;
		timesTriggered++;
	}

	virtual ObjectPtr getReceivedObject() {
		return this->receivedObject;
	}
	virtual shared_ptr<T> getReceivedArgs() {
		return this->receivedArgs;
	}
	virtual int getTimesTriggeredToHandleEvent() {
		return timesTriggered;
	}
};

#endif //UTILITIES_EVENTLISTENER_MOCKS_H