#include "Composite.h"

Composite::~Composite() {}
Composite::Composite() {}

void Composite::setParent(CompositePtr parent) {
    this->parent = parent;
}

CompositePtr Composite::getParent() {
    return parent.lock();
}

CompositePtr Composite::sharedFromThis() {
    CompositePtr me = std::dynamic_pointer_cast<Composite>(this->shared_from_this());
    if(!me) throw new SharedFromThisException();
    return me;
}

int Composite::getRow() {
    if(getParent())
        return getParent()->childPos(sharedFromThis());
    return -1;
}

