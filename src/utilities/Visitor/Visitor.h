#ifndef UTILITIES_VISITOR_H
#define UTILITIES_VISITOR_H

#include <memory>

class Visitor;
typedef std::shared_ptr <Visitor> VisitorPtr;
class Visitor {
public:
    virtual ~Visitor() {}
protected:
    Visitor() {}
};

#endif //UTILITIES_VISITOR_H