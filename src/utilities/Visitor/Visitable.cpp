#include "Visitable.h"

#include <iostream>
#include <sstream>

Visitable::~Visitable() {

}

Visitable::Visitable() {

}

void Visitable::throwVisitorCastException() {
    throw new VisitorCastException();
}

const char *VisitorCastException::what() const throw() {
    std::ostringstream getNr;
    getNr << "Invalid visitor!";
    return getNr.str().c_str();
}
