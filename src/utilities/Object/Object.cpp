#include <memory>
#include "Object.h"
#include <sstream>

Object::~Object() {}
Object::Object() {}

void Object::addLogger(std::shared_ptr<Logger> logger) {
    LoggingObject::addLogger(logger);
}

void Object::removeLogger(std::shared_ptr<Logger> logger) {
    LoggingObject::removeLogger(logger);
}

ObjectPtr Object::sharedFromThis() {
    ObjectPtr me = std::dynamic_pointer_cast<Object>(this->shared_from_this());
    return me;
}

const char* SharedFromThisException::what() const throw(){
    std::ostringstream getNr;
    getNr << "Shared from this exception";
    return getNr.str().c_str();
}
