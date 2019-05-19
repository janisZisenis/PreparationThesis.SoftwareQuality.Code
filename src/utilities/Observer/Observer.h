#ifndef UTILITIES_OBSERVER_H
#define UTILITIES_OBSERVER_H

#include <memory>

class Observer;
typedef std::shared_ptr<Observer> ObserverPtr;
class Observer{
protected:
    Observer(){}
public:
    virtual ~Observer(){}

public:
    virtual void update() = 0;
};

#endif //UTILITIES_OBSERVER_H