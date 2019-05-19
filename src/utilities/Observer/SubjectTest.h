#ifndef UTILITIES_SUBJECTTEST_H
#define UTILITIES_SUBJECTTEST_H

#include "gmock/gmock.h"

#include "Subject.h"
#include "ObserverMocks.h"

class SubjectTest : public Subject, public testing::Test {
protected:
    virtual void SetUp() override {}
};

class SomeObserverAttached : public SubjectTest {
protected:
    virtual void SetUp() override {
        SubjectTest::SetUp();;

        this->attach(first);
        this->attach(second);
        this->attach(third);
    }
    ObserverSpyPtr first = ObserverSpy::getNewInstance();
    ObserverSpyPtr second = ObserverSpy::getNewInstance();
    ObserverSpyPtr third = ObserverSpy::getNewInstance();
};

class SomeObserverDetached : public SomeObserverAttached {
protected:
    virtual void SetUp() override {
        SomeObserverAttached::SetUp();;

        this->detach(first);
        this->detach(third);
    }
};

class SomeObserverFreed : public SomeObserverAttached {
protected:
    virtual void SetUp() override {
        SomeObserverAttached::SetUp();;

        first.reset();
        third.reset();
    }
};

#endif //UTILITIES_SUBJECTTEST_H