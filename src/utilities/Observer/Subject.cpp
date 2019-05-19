#include "Subject.h"
#include "Observer.h"


void Subject::attach(std::shared_ptr<Observer> observer) {
    observers.push_back(observer);
}

void Subject::detach(std::shared_ptr<Observer> observer) {
    for(int i = observers.size()-1; i >= 0; i--) {
        if (getLockedObserver(i) == observer )
            removeObserver(i);
    }
}

void Subject::notify() {
    for(int i = observers.size()-1; i >= 0; i--)
        if(getLockedObserver(i))
            getLockedObserver(i)->update();
}

ObserverPtr Subject::getLockedObserver(int index) {
    ObserverPtr o = nullptr;

    if(observers[index].lock())
        o = observers[index].lock();
    else
        removeObserver(index);

    return o;
}

void Subject::removeObserver(int index) {
    observers.erase(observers.begin()+index);
}

