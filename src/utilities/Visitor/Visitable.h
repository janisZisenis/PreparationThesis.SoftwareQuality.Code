#ifndef UTILITIES_VISITABLE_H
#define UTILITIES_VISITABLE_H

#include <memory>
#include <utilities/utilities_Export.h>

class Visitor;

class Visitable;
typedef std::shared_ptr<Visitable> VisitablePtr;
class utilities_EXPORT Visitable {
public:
    virtual ~Visitable();
protected:
    Visitable();

public:
	virtual void accept(std::shared_ptr<Visitor> visitor) = 0;
	virtual void throwVisitorCastException();
};

class VisitorCastException : public std::exception {
	const char *what() const throw();
};

#endif //UTILITIES_VISITABLE_H