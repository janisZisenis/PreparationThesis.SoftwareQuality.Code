#include "WaveBinder.h"
#include "model/HierarchyNode/Wave/Wave.h"

#include "model/HierarchyNode/WaveDynamic/WaveDynamic.h"

WaveBinderPtr WaveBinder::getNewInstance(WavePtr node) {
    return WaveBinderPtr(new WaveBinder(node));
}

WaveBinder::~WaveBinder() {}

WaveBinder::WaveBinder(WavePtr node) : child(node) {}

void WaveBinder::visit(WaveDynamicPtr waveDynamic) {
    WavePtr oldChild = waveDynamic->getWave();

    waveDynamic->setWave(child);

    child = oldChild;
}
