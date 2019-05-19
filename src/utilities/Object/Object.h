#ifndef UTILITIES_OBJECT_H
#define UTILITIES_OBJECT_H

#include <memory>
#include <utilities/utilities_Export.h>
#include "LoggingObject.h"

class Object;
typedef std::shared_ptr<Object> ObjectPtr;
class utilities_EXPORT Object : public LoggingObject, public std::enable_shared_from_this<Object> {
public:
    virtual ~Object();
protected:
    Object();

private:
    static void addLogger(std::shared_ptr<Logger> logger);
    static void removeLogger(std::shared_ptr<Logger> logger);

private:
    ObjectPtr sharedFromThis();
};

class utilities_EXPORT SharedFromThisException : public std::exception {
public:
    virtual const char *what() const throw();
};


#endif //UTILITIES_OBJECT_H