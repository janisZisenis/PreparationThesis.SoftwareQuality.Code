#include "Wave.h"
#include <model/Binder/WaveBinder/WaveBinder.h>
#include <model/Editor/WaveEditor/WaveEditor.h>
#include "WaveVisitor.h"
#include "WaveType.h"
#include "utilities/Math/Math.h"

int Wave::timesInstantiated = 0;

WavePtr Wave::getNewInstance() {
    return WavePtr(new Wave());
}

Wave::~Wave() {}

Wave::Wave() : HierarchyNode(NodeTypes::wave(), NodeTypes::wave()) {
    initializeName(timesInstantiated++);
}

void Wave::setLength(double length) {
    this->length = length;
    nodeChanged(sharedFromThis());
}

double Wave::getLength() {
    return length;
}

void Wave::setPeriod(double period) {
    this->period = period;
    nodeChanged(sharedFromThis());
}

double Wave::getPeriod() {
    return period;
}

void Wave::setHeight(double height) {
    this->height = height;
    nodeChanged(sharedFromThis());
}

double Wave::getHeight() {
    return height;
}

void Wave::setWaterDepth(double waterDepth) {
    this->waterDepth = waterDepth;
    nodeChanged(sharedFromThis());
}

double Wave::getWaterDepth() {
    return waterDepth;
}

double Wave::getAngularFrequency() {
    return 2. * utilities::Math::pi() / period;
}

double Wave::getAngularNumber() {
    return 2. * utilities::Math::pi() / length;
}

VisitorPtr Wave::makeBinder() {
    return WaveBinder::getNewInstance(sharedFromThis());
}

EditorPtr Wave::makeEditor() {
    return WaveEditor::getNewInstance(sharedFromThis());
}

void Wave::accept(VisitorPtr visitor) {
    WaveVisitorPtr castVisitor = std::dynamic_pointer_cast<WaveVisitor>(visitor);
    if (!castVisitor) HierarchyNode::accept(visitor);
    castVisitor->visit(sharedFromThis());
}

WavePtr Wave::sharedFromThis() {
    WavePtr me = std::dynamic_pointer_cast<Wave>(this->shared_from_this());
    if (!me) throw new SharedFromThisException();
    return me;
}




