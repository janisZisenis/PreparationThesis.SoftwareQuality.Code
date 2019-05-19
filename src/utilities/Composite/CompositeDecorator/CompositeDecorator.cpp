#include "CompositeDecorator.h"

CompositeDecorator::~CompositeDecorator() {}
CompositeDecorator::CompositeDecorator(CompositePtr composite) : composite(composite) {}

void CompositeDecorator::insertChild(CompositePtr child, int index) {
    composite->insertChild(child, index);
    child->setParent(sharedFromThis());
}

void CompositeDecorator::appendChild(CompositePtr child) {
    composite->appendChild(child);
    child->setParent(sharedFromThis());
}

void CompositeDecorator::setChildAt(CompositePtr child, int index) {
    composite->setChildAt(child, index);
    child->setParent(sharedFromThis());
}

void CompositeDecorator::removeChild(int index) {
    composite->removeChild(index);
}

CompositePtr CompositeDecorator::getChildAt(int pos) {
    return composite->getChildAt(pos);
}

int CompositeDecorator::getChildCount() {
    return composite->getChildCount();
}

int CompositeDecorator::childPos(CompositePtr child) {
    return composite->childPos(child);
}

CompositeDecoratorPtr CompositeDecorator::sharedFromThis() {
    CompositeDecoratorPtr me = std::dynamic_pointer_cast<CompositeDecorator>(this->shared_from_this());
    if(!me) throw new SharedFromThisException();
    return me;
}


