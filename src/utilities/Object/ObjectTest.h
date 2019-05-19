#ifndef UTILITIES_OBJECTTEST_H
#define UTILITIES_OBJECTTEST_H

#include "gmock/gmock.h"
#include "utilities/Logger/LoggerMocks.h"
#include "ObjectMocks.h"
#include "LoggingObject.h"

class ObjectTest : public Object, public testing::Test {
protected:
    virtual void SetUp() override {}
};

class SomeLoggerAdded : public ObjectTest
{
protected:
    virtual void SetUp() override {
        LoggingObject::addLogger(first);
        LoggingObject::addLogger(second);
        LoggingObject::addLogger(third);
        LoggingObject::addLogger(fourth);
    }
    LoggerSpyPtr first = LoggerSpy::getNewInstance();
    LoggerSpyPtr second = LoggerSpy::getNewInstance();
    LoggerSpyPtr third = LoggerSpy::getNewInstance();
    LoggerSpyPtr fourth = LoggerSpy::getNewInstance();

    std::string expectedMessage = "log some words";
};

class SomeAddedLoggerRemoved : public SomeLoggerAdded{
protected:
    virtual void SetUp() override{
        SomeLoggerAdded::SetUp();

        LoggingObject::removeLogger(second);
        LoggingObject::removeLogger(third);
    }
};

#endif //UTILITIES_OBJECTTEST_H