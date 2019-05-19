#ifndef UTILITIES_LOGGINGOBJECT_H
#define UTILITIES_LOGGINGOBJECT_H

#include <memory>
#include <vector>
#include <utilities/utilities_Export.h>
#include <string>

class Logger;

class LoggingObject;
typedef std::shared_ptr<LoggingObject> LoggingObjectPtr;

class utilities_EXPORT LoggingObject {
public:
    virtual ~LoggingObject() {}
protected:
    LoggingObject() {}

public:
    static void addLogger(std::shared_ptr<Logger> logger);
    static void removeLogger(std::shared_ptr<Logger> logger);
protected:
    void log(const std::string logMessage);

private:
    static std::vector<std::shared_ptr<Logger> > loggers;
};

#endif //UTILITIES_LOGGINGOBJECT_H