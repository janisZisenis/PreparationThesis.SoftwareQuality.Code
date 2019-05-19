#include "Water.h"
#include <model/Binder/WaterBinder/WaterBinder.h>
#include <model/Editor/WaterEditor/WaterEditor.h>
#include "WaterVisitor.h"
#include "WaterType.h"

int Water::timesInstantiated = 0;

WaterPtr Water::getNewInstance() {
    return WaterPtr(new Water());
}

Water::~Water() {}

Water::Water() : HierarchyNode(NodeTypes::water(), NodeTypes::water()) {
    initializeName(timesInstantiated++);
}

void Water::setDensity(double density) {
    this->density = density;
    nodeChanged(sharedFromThis());
}

double Water::getDensity() {
    return density;
}

void Water::setViscosity(double viscosity) {
    this->viscosity = viscosity;
    nodeChanged(sharedFromThis());
}

double Water::getViscosity() {
    return viscosity;
}

VisitorPtr Water::makeBinder() {
    return WaterBinder::getNewInstance(sharedFromThis());
}

EditorPtr Water::makeEditor() {
    return WaterEditor::getNewInstance(sharedFromThis());
}

void Water::accept(VisitorPtr visitor) {
    WaterVisitorPtr castVisitor = std::dynamic_pointer_cast<WaterVisitor>(visitor);
    if(!castVisitor) HierarchyNode::accept(visitor);
    castVisitor->visit(sharedFromThis());}

WaterPtr Water::sharedFromThis() {
    WaterPtr me = std::dynamic_pointer_cast<Water>(this->shared_from_this());
    if (!me) throw new SharedFromThisException();
    return me;
}

