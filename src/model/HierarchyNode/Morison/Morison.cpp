#include "Morison.h"

#include <model/Binder/MorisonBinder/MorisonBinder.h>
#include <model/Editor/MorisonEditor/MorisonEditor.h>

#include <model/HierarchyNode/Pile/Pile.h>
#include <model/HierarchyNode/WaveDynamic/WaveDynamic.h>
#include <model/HierarchyNode/Water/Water.h>

#include "MorisonType.h"
#include "MorisonChildTypes.h"
#include "MorisonVisitor.h"

int Morison::timesInstantiated = 0;

MorisonPtr Morison::getNewInstance() {
    return MorisonPtr(new Morison());
}

Morison::~Morison() {}

Morison::Morison() : HierarchyNode(NodeTypes::morison(), NodeTypes::morison()) {
    initializeName(timesInstantiated++);
}

void Morison::setPile(PilePtr pile) {
    this->pile = pile;
    childReplaced(pile, NodeTypes::pile());
}

PilePtr Morison::getPile() {
    return pile;
}

void Morison::setWater(WaterPtr water) {
    this->water = water;
    childReplaced(water, NodeTypes::water());
}

WaterPtr Morison::getWater() {
    return water;
}

void Morison::setWaveDynamic(WaveDynamicPtr waveDynamic) {
    this->waveDynamic = waveDynamic;
    childReplaced(waveDynamic, NodeTypes::waveDynamic());
}

WaveDynamicPtr Morison::getWaveDynamic() {
    return waveDynamic;
}

VisitorPtr Morison::makeBinder() {
    return MorisonBinder::getNewInstance(sharedFromThis());
}

EditorPtr Morison::makeEditor() {
    return MorisonEditor::getNewInstance(sharedFromThis());
}

void Morison::accept(VisitorPtr visitor) {
    MorisonVisitorPtr castVisitor = std::dynamic_pointer_cast<MorisonVisitor>(visitor);
    if(!castVisitor) HierarchyNode::accept(visitor);
    castVisitor->visit(sharedFromThis());}

MorisonPtr Morison::sharedFromThis() {
    MorisonPtr me = std::dynamic_pointer_cast<Morison>(this->shared_from_this());
    if (!me) throw new SharedFromThisException();
    return me;
}

bool Morison::canBind(HierarchyNodePtr node) {
    if(!node) return false;

    return (node->getType() == NodeTypes::pile()
            || node->getType() == NodeTypes::water()
            || node->getType() == NodeTypes::waveDynamic());
}


