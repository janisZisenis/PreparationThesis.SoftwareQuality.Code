#ifndef UTILITIES_EVENT_H
#define UTILITIES_EVENT_H

#include "EventListener.h"
#include "EventArgs.h"
#include <vector>

template <class T> using WeakEventListenerPtr = weak_ptr < EventListener<T> >;

template <class T> class Event;
template <class T> using EventPtr = shared_ptr < Event<T> >;

template <class T> class Event{
public:
	static EventPtr<T> getNewInstance() {
		return EventPtr<T>(new Event<T>());
	}
    virtual ~Event<T>(){}
protected:
    Event<T>(){}

public:
	virtual void attach(EventListenerPtr<T> listener) {
		weakListeners.push_back(listener);
	}
	virtual void detach(EventListenerPtr<T> listener) {
		for (int i = 0; i < weakListeners.size(); i++)
			if (weakListeners[i].lock() == listener) {
				weakListeners.erase(weakListeners.begin() + i);
				i--;
			}
	}

	virtual void operator += (EventListenerPtr<T> listener) { attach(listener); }
	virtual void operator -= (EventListenerPtr<T> listener) { detach(listener); }

	virtual void notifyListeners(ObjectPtr sender, shared_ptr<T> e) {
		for (int i = 0; i < weakListeners.size(); i++)
			if (!weakListeners[i].lock()) {
				eraseUnlockableWeakPtr(i);
				i--;
			}
			else weakListeners[i].lock()->handleEvent(sender, e);
	}
	virtual void appendListenersOf(EventPtr<T> event) {
		for (int i = 0; i < event->weakListeners.size(); i++) {
			if (weakListenersContains(event->weakListeners[i].lock())) continue;

			weakListeners.push_back(event->weakListeners[i]);
		}
	}
protected:
	virtual void eraseUnlockableWeakPtr(int index) {
		weakListeners.erase(weakListeners.begin() + index);
	}
	virtual bool weakListenersContains(EventListenerPtr<T> listener) {
		for (int i = 0; i < weakListeners.size(); i++)
			if (weakListeners[i].lock() == listener)
				return true;

		return false;
	}

private:
	vector<WeakEventListenerPtr<T> > weakListeners;
};

#endif //UTILITIES_EVENT_H