#include "WaveDynamic.h"

#include "WaveDynamicType.h"
#include "WaveDynamicChildTypes.h"
#include "WaveDynamicVisitor.h"

#include <model/Binder/WaveDynamicBinder/WaveDynamicBinder.h>
#include <model/Editor/WaveDynamicEditor/WaveDynamicEditor.h>
#include <utilities/Math/Math.h>
#include "model/HierarchyNode/CoordinateSystem/CoordinateSystem.h"
#include "model/HierarchyNode/Wave/Wave.h"

int WaveDynamic::timesInstantiated = 0;

WaveDynamicPtr WaveDynamic::getNewInstance() {
    return WaveDynamicPtr(new WaveDynamic());
}

WaveDynamic::~WaveDynamic() {}

WaveDynamic::WaveDynamic() : HierarchyNode(NodeTypes::waveDynamic(), NodeTypes::waveDynamic()) {
    initializeName(timesInstantiated++);
}

bool WaveDynamic::canBind(HierarchyNodePtr node) {
    if (!node) return false;

    return (node->getType() == NodeTypes::coordinateSystem()
            || node->getType() == NodeTypes::wave());
}

void WaveDynamic::setCoordinateSystem(CoordinateSystemPtr coordinateSystem) {
    disconnectFromNode(this->coordinateSystem);
    connectToNode(coordinateSystem);
    this->coordinateSystem = coordinateSystem;
    childReplaced(coordinateSystem, NodeTypes::coordinateSystem());
}

CoordinateSystemPtr WaveDynamic::getCoordinateSystem() {
    return this->coordinateSystem;
}

void WaveDynamic::setWave(WavePtr wave) {
    disconnectFromNode(this->wave);
    connectToNode(wave);
    this->wave = wave;
    childReplaced(wave, NodeTypes::wave());
}

WavePtr WaveDynamic::getWave() {
    return this->wave;
}

VisitorPtr WaveDynamic::makeBinder() {
    return WaveDynamicBinder::getNewInstance(sharedFromThis());
}

EditorPtr WaveDynamic::makeEditor() {
    return WaveDynamicEditor::getNewInstance(sharedFromThis());
}

WaveDynamicPtr WaveDynamic::sharedFromThis() {
    WaveDynamicPtr me = std::dynamic_pointer_cast<WaveDynamic>(this->shared_from_this());
    if (!me) throw new SharedFromThisException();
    return me;
}

void WaveDynamic::accept(VisitorPtr visitor) {
    WaveDynamicVisitorPtr castVisitor = std::dynamic_pointer_cast<WaveDynamicVisitor>(visitor);
    if (!castVisitor) HierarchyNode::accept(visitor);
    castVisitor->visit(sharedFromThis());
}

double WaveDynamic::getAngularWaveNumber() {
    return wave->getAngularNumber();
}

double WaveDynamic::getAngularWaveFrequency() {
    return wave->getAngularFrequency();
}

double WaveDynamic::getWaveLength() {
    return wave->getLength();
}

double WaveDynamic::getWavePeriod() {
    return wave->getPeriod();
}

double WaveDynamic::getWaveHeight() {
    return wave->getHeight();
}

double WaveDynamic::getWaterDepth() {
    return wave->getWaterDepth();
}

double WaveDynamic::getWaterSurfaceDisplacement() {
    return calcWaveProfile(wave->getHeight(), wave->getAngularNumber(), wave->getAngularFrequency(),
                           coordinateSystem->getX(), coordinateSystem->getT());
}

double WaveDynamic::getSpatialWaterProfile(double x) {
    return calcWaveProfile(wave->getHeight(), wave->getAngularNumber(), wave->getAngularFrequency(), x,
                           coordinateSystem->getT());
}

double WaveDynamic::getTimeWaterProfile(double t) {
    return calcWaveProfile(wave->getHeight(), wave->getAngularNumber(), wave->getAngularFrequency(),
                           coordinateSystem->getX(), t);
}

double WaveDynamic::calcWaveProfile(double waveHeight, double k, double omega, double x, double t) {
    return waveHeight / 2 * utilities::Math::cos(k * x - omega * t);
}




