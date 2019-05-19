#include "CoordinateSystem.h"

#include <model/Binder/CoordinateSystemBinder/CoordinateSystemBinder.h>
#include <model/Editor/CoordinateSystemEditor/CoordinateSystemEditor.h>
#include "CoordinateSystemType.h"
#include "CoordinateSystemVisitor.h"

int CoordinateSystem::timesInstantiated = 0;

CoordinateSystemPtr CoordinateSystem::getNewInstance() {
    return CoordinateSystemPtr(new CoordinateSystem());
}

CoordinateSystem::~CoordinateSystem() {}

CoordinateSystem::CoordinateSystem() : HierarchyNode(NodeTypes::coordinateSystem(), NodeTypes::coordinateSystem()) {
    initializeName(timesInstantiated++);
}

void CoordinateSystem::setX(double x) {
    this->x = x;
    nodeChanged(sharedFromThis());
}

double CoordinateSystem::getX() {
    return x;
}

void CoordinateSystem::setT(double t) {
    this->t = t;
    nodeChanged(sharedFromThis());
}

double CoordinateSystem::getT() {
    return t;
}

void CoordinateSystem::setZ(double z) {
    this->z = z;
    nodeChanged(sharedFromThis());
}

double CoordinateSystem::getZ() {
    return z;
}

VisitorPtr CoordinateSystem::makeBinder() {
    return CoordinateSystemBinder::getNewInstance(sharedFromThis());
}

EditorPtr CoordinateSystem::makeEditor() {
    return CoordinateSystemEditor::getNewInstance(sharedFromThis());
}

void CoordinateSystem::accept(VisitorPtr visitor) {
    CoordinateSystemVisitorPtr castVisitor = std::dynamic_pointer_cast<CoordinateSystemVisitor>(visitor);
    if(!castVisitor) HierarchyNode::accept(visitor);
    castVisitor->visit(sharedFromThis());}

CoordinateSystemPtr CoordinateSystem::sharedFromThis() {
    CoordinateSystemPtr me = std::dynamic_pointer_cast<CoordinateSystem>(this->shared_from_this());
    if (!me) throw new SharedFromThisException();
    return me;
}




