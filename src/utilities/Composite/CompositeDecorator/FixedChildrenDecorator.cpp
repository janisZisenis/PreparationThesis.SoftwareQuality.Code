//#include "FixedChildrenDecorator.h"
//
//FixedChildrenDecoratorPtr FixedChildrenDecorator::getNewInstance(int numOfChildren, CompositePtr composite) {
//    return FixedChildrenDecoratorPtr(new FixedChildrenDecorator(numOfChildren, composite));
//}
//FixedChildrenDecorator::~FixedChildrenDecorator() {}
//FixedChildrenDecorator::FixedChildrenDecorator(int numOfChildren, CompositePtr composite) : CompositeDecorator(composite), numOfChildren(numOfChildren) {}
//
//FixedChildrenDecoratorPtr FixedChildrenDecorator::sharedFromThis() {
//    FixedChildrenDecoratorPtr me = std::dynamic_pointer_cast<FixedChildrenDecorator>(this->shared_from_this());
//    if(!me) throw new SharedFromThisException();
//    return me;
//}
//
//void FixedChildrenDecorator::insertChild(CompositePtr child, int index) {}
//void FixedChildrenDecorator::appendChild(CompositePtr child) {}
//void FixedChildrenDecorator::removeChild(int index) {}
