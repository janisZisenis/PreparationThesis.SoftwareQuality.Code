#include "CoordinateSystemBinder.h"
#include "model/HierarchyNode/CoordinateSystem/CoordinateSystem.h"

#include "model/HierarchyNode/WaveDynamic/WaveDynamic.h"


CoordinateSystemBinderPtr CoordinateSystemBinder::getNewInstance(CoordinateSystemPtr node) {
    return CoordinateSystemBinderPtr(new CoordinateSystemBinder(node));
}

CoordinateSystemBinder::~CoordinateSystemBinder() {}

CoordinateSystemBinder::CoordinateSystemBinder(CoordinateSystemPtr node) : child(node){}

void CoordinateSystemBinder::visit(WaveDynamicPtr waveDynamic) {
    CoordinateSystemPtr oldChild = waveDynamic->getCoordinateSystem();

    waveDynamic->setCoordinateSystem(child);

    this->child = oldChild;
}