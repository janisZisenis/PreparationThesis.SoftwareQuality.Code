#include "SedimentTransport.h"

#include <model/Binder/SedimentTransportBinder/SedimentTransportBinder.h>
#include <model/Editor/SedimentTransportEditor/SedimentTransportEditor.h>

#include "SedimentTransportType.h"
#include "SedimentTransportChildTypes.h"

#include "model/HierarchyNode/WaveDynamic/WaveDynamic.h"
#include "model/HierarchyNode/Sediment/Sediment.h"
#include "model/HierarchyNode/Water/Water.h"
#include "SedimentTransportVisitor.h"

int SedimentTransport::timesInstantiated = 0;

SedimentTransportPtr SedimentTransport::getNewInstance() {
    return SedimentTransportPtr(new SedimentTransport());
}

SedimentTransport::~SedimentTransport() {}

SedimentTransport::SedimentTransport() : HierarchyNode(NodeTypes::sedimentTransport(), NodeTypes::sedimentTransport()) {
    initializeName(timesInstantiated++);
}

bool SedimentTransport::canBind(HierarchyNodePtr node) {
    if(!node) return false;

    return (node->getType() == NodeTypes::sediment()
            || node->getType() == NodeTypes::water()
            || node->getType() == NodeTypes::waveDynamic());
}

void SedimentTransport::setWater(WaterPtr water) {
    this->water = water;
    childReplaced(water, NodeTypes::water());
}

WaterPtr SedimentTransport::getWater() {
    return water;
}

void SedimentTransport::setWaveDynamic(WaveDynamicPtr waveDynamic) {
    this->waveDynamic = waveDynamic;
    childReplaced(waveDynamic, NodeTypes::waveDynamic());
}

WaveDynamicPtr SedimentTransport::getWaveDynamic() {
    return this->waveDynamic;
}

void SedimentTransport::setSediment(SedimentPtr sediment) {
    this->sediment = sediment;
    childReplaced(sediment, NodeTypes::sediment());
}

SedimentPtr SedimentTransport::getSediment() {
    return this->sediment;
}

VisitorPtr SedimentTransport::makeBinder() {
    return SedimentTransportBinder::getNewInstance(sharedFromThis());
}

EditorPtr SedimentTransport::makeEditor() {
    return SedimentTransportEditor::getNewInstance(sharedFromThis());
}

void SedimentTransport::accept(VisitorPtr visitor) {
    SedimentTransportVisitorPtr castVisitor = std::dynamic_pointer_cast<SedimentTransportVisitor>(visitor);
    if(!castVisitor) HierarchyNode::accept(visitor);
    castVisitor->visit(sharedFromThis());
}

SedimentTransportPtr SedimentTransport::sharedFromThis() {
    SedimentTransportPtr me = std::dynamic_pointer_cast<SedimentTransport>(this->shared_from_this());
    if (!me) throw new SharedFromThisException();
    return me;
}




