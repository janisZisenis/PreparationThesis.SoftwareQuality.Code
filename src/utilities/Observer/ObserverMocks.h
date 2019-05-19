#ifndef UTILITIES_OBSERVERMOCKS_H
#define UTILITIES_OBSERVERMOCKS_H

#include "Observer.h"

class ObserverDummy;
typedef std::shared_ptr<ObserverDummy> ObserverDummyPtr;
class ObserverDummy : public Observer{
public:
    static ObserverDummyPtr getNewInstance(){
        return ObserverDummyPtr(new ObserverDummy());
    }
    virtual ~ObserverDummy(){}
protected:
    ObserverDummy() : Observer() {}

public:
    virtual void update() override {};
};

class ObserverSpy;
typedef std::shared_ptr<ObserverSpy> ObserverSpyPtr;
class ObserverSpy : public ObserverDummy{
public:
    static ObserverSpyPtr getNewInstance(){
        return ObserverSpyPtr(new ObserverSpy());
    }
    virtual ~ObserverSpy(){}
protected:
    ObserverSpy() : ObserverDummy() {}

public:
    virtual void update() override {
        ObserverDummy::update();
        this->wasUpdated = true;
    };

    virtual bool getWasUpdated(){
        return this->wasUpdated;
    }
private:
    bool wasUpdated = false;
};

#endif //UTILITIES_OBSERVERMOCKS_H