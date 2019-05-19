#ifndef UTILITIES_LOGGER_H
#define UTILITIES_LOGGER_H

#include <memory>
#include <string>

class Logger;
typedef std::shared_ptr<Logger> LoggerPtr;

class Logger{
public:
    virtual ~Logger() {}
protected:
    Logger() {}

public:
    virtual void log(std::string logMessage) = 0;
};

#endif //UTILITIES_LOGGER_H