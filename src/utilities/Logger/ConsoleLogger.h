#ifndef UTILITIES_CONSOLELOGGER_H
#define UTILITIES_CONSOLELOGGER_H

#include "Logger.h"
#include <utilities/utilities_Export.h>

class ConsoleLogger;
typedef std::shared_ptr<ConsoleLogger> ConsoleLoggerPtr;

class utilities_EXPORT ConsoleLogger : public Logger{
public:
    static ConsoleLoggerPtr getNewInstance();
    virtual ~ConsoleLogger();
private:
    ConsoleLogger();
public:
    virtual void log(std::string logMessage);
};

#endif //UTILITIES_CONSOLELOGGER_H