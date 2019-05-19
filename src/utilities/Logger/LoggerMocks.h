#ifndef UTILITIES_LOGGERMOCKS_H
#define UTILITIES_LOGGERMOCKS_H

#include <memory>
#include "Logger.h"

class LoggerDummy;
typedef std::shared_ptr<LoggerDummy> LoggerDummyPtr;

class LoggerDummy : public Logger{
public:
    static LoggerDummyPtr getNewInstance(){
        return LoggerDummyPtr(new LoggerDummy());
    }
    ~LoggerDummy(){}
protected:
    LoggerDummy() : Logger() {}

public:
    virtual void log(std::string logMessage) override {}
};

class LoggerSpy;
typedef std::shared_ptr<LoggerSpy> LoggerSpyPtr;
class LoggerSpy : public LoggerDummy{
public:
    static LoggerSpyPtr getNewInstance(){
        return LoggerSpyPtr(new LoggerSpy());
    }
    ~LoggerSpy(){}
protected:
    LoggerSpy() : LoggerDummy() {}

public:
    virtual void log(std::string logMessage) override {
        this->receivedMessage = logMessage;
    }
    std::string getReceivedMessage(){
        return this->receivedMessage;
    }

private:
    std::string receivedMessage = "";
};

#endif //UTILITIES_LOGGERMOCKS_H