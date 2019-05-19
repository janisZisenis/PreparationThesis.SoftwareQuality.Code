#include "Sediment.h"
#include <model/Binder/SedimentBinder/SedimentBinder.h>
#include <model/Editor/SedimentEditor/SedimentEditor.h>
#include "SedimentType.h"
#include "SedimentVisitor.h"

int Sediment::timesInstantiated = 0;

SedimentPtr Sediment::getNewInstance() {
    return SedimentPtr(new Sediment());
}

Sediment::~Sediment() {}

Sediment::Sediment() : HierarchyNode(NodeTypes::sediment(), NodeTypes::sediment()) {
	initializeName(timesInstantiated++);
}

void Sediment::setDensity(double density) {
    this->density = density;
    nodeChanged(sharedFromThis());
}

double Sediment::getDensity() {
    return density;
}

VisitorPtr Sediment::makeBinder() {
    return SedimentBinder::getNewInstance(sharedFromThis());
}

EditorPtr Sediment::makeEditor() {
    return SedimentEditor::getNewInstance(sharedFromThis());
}

void Sediment::accept(VisitorPtr visitor) {
    SedimentVisitorPtr castVisitor = std::dynamic_pointer_cast<SedimentVisitor>(visitor);
    if(!castVisitor) HierarchyNode::accept(visitor);
    castVisitor->visit(sharedFromThis());}

SedimentPtr Sediment::sharedFromThis() {
    SedimentPtr me = std::dynamic_pointer_cast<Sediment>(this->shared_from_this());
    if (!me) throw new SharedFromThisException();
    return me;
}



