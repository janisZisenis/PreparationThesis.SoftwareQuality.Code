#include "Pile.h"
#include <model/Binder/PileBinder/PileBinder.h>
#include <model/Editor/PileEditor/PileEditor.h>
#include "PileType.h"
#include "PileVisitor.h"

int Pile::timesInstantiated = 0;

PilePtr Pile::getNewInstance() {
    return PilePtr(new Pile());
}

Pile::~Pile() {}

Pile::Pile() : HierarchyNode(NodeTypes::pile(), NodeTypes::pile()) {
    initializeName(timesInstantiated++);
}

void Pile::setDiameter(double diameter) {
    this->diameter = diameter;
    nodeChanged(sharedFromThis());
}

double Pile::getDiameter() {
    return diameter;
}

VisitorPtr Pile::makeBinder() {
    return PileBinder::getNewInstance(sharedFromThis());
}

EditorPtr Pile::makeEditor() {
    return PileEditor::getNewInstance(sharedFromThis());
}

void Pile::accept(VisitorPtr visitor) {
    PileVisitorPtr castVisitor = std::dynamic_pointer_cast<PileVisitor>(visitor);
    if(!castVisitor) HierarchyNode::accept(visitor);
    castVisitor->visit(sharedFromThis());}

PilePtr Pile::sharedFromThis() {
    PilePtr me = std::dynamic_pointer_cast<Pile>(this->shared_from_this());
    if (!me) throw new SharedFromThisException();
    return me;
}




