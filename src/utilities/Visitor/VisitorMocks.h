#ifndef UTILITIES_VISITORMOCKS_H
#define UTILITIES_VISITORMOCKS_H

#include "Visitor.h"

class InvalidVisitorDummy;
typedef std::shared_ptr<InvalidVisitorDummy> InvalidVisitorDummyPtr;
class InvalidVisitorDummy : public Visitor {
public:
    static InvalidVisitorDummyPtr getNewInstance() {
        return InvalidVisitorDummyPtr(new InvalidVisitorDummy());
    }
    virtual ~InvalidVisitorDummy() {}
protected:
    InvalidVisitorDummy() {}
};

#endif //UTILITIES_VISITORMOCKS_H