#ifndef UTILITIES_EVENTMOCKS_H
#define UTILITIES_EVENTMOCKS_H

#include "Event.h"
#include <vector>

template <class T> class EventSubClass;
template <class T> using EventSubClassPtr = shared_ptr < EventSubClass<T> >;
template <class T> class EventSubClass : public Event<T> {
public:
    static EventSubClassPtr<T> getNewInstance() {
        return EventSubClassPtr<T>(new EventSubClass<T>());
    }
    virtual ~EventSubClass<T>(){}
protected:
    EventSubClass<T>() : Event<T>() {}

public:
	virtual void notifyListeners(ObjectPtr sender, shared_ptr<T> e) override {
		this->receivedObjects.push_back(sender);
		this->receivedArgs.push_back(e);
	}

	virtual ObjectPtr getLastReceivedObject() {
		return this->receivedObjects[receivedObjects.size() - 1];
	}
	virtual vector<ObjectPtr> getReceivedObjectHistory() {
		return this->receivedObjects;
	}
	virtual shared_ptr<T> getLastReceivedArgs() {
		return this->receivedArgs[receivedArgs.size() - 1];
	}
	virtual vector<shared_ptr<T> > getReceivedArgsHistory() {
		return this->receivedArgs;
	}
	virtual EventPtr<T> getReceivedEvent() {
		return this->receivedEvent;
	}
	virtual void appendListenersOf(EventPtr<T> event) override {
		this->receivedEvent = event;
	}
	virtual bool contains(EventListenerPtr<T> listener) {
		return this->weakListenersContains(listener);
	}
private:
	vector<ObjectPtr> receivedObjects;
	vector<shared_ptr<T> >receivedArgs;
	EventPtr<T> receivedEvent;
};

#endif //UTILITIES_EVENTMOCKS_H