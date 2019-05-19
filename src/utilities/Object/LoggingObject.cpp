#include "LoggingObject.h"
#include "utilities/Logger/Logger.h"

std::vector<std::shared_ptr<Logger> > LoggingObject::loggers;

void LoggingObject::addLogger(LoggerPtr logger) {
    loggers.push_back(logger);
}

void LoggingObject::removeLogger(LoggerPtr logger) {
    std::vector<LoggerPtr>::iterator it = std::find(loggers.begin(),loggers.end(), logger);

    if(it != loggers.end())
        loggers.erase(it);
}

void LoggingObject::log(const std::string logMessage) {
    for(LoggerPtr logger : loggers)
        logger->log(logMessage);
}
