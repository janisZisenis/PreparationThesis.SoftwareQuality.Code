#include "WaveDynamicBinder.h"
#include "model/HierarchyNode/WaveDynamic/WaveDynamic.h"

#include "model/HierarchyNode/Morison/Morison.h"
#include "model/HierarchyNode/SedimentTransport/SedimentTransport.h"

WaveDynamicBinderPtr WaveDynamicBinder::getNewInstance(WaveDynamicPtr node) {
    return WaveDynamicBinderPtr(new WaveDynamicBinder(node));
}

WaveDynamicBinder::~WaveDynamicBinder() {}

WaveDynamicBinder::WaveDynamicBinder(WaveDynamicPtr node) : child(node) {}

void WaveDynamicBinder::visit(MorisonPtr morison) {
    WaveDynamicPtr oldChild = morison->getWaveDynamic();

    morison->setWaveDynamic(child);

    this->child = oldChild;
}

void WaveDynamicBinder::visit(SedimentTransportPtr sedimentTransport) {
    WaveDynamicPtr oldChild = sedimentTransport->getWaveDynamic();

    sedimentTransport->setWaveDynamic(child);

    this->child = oldChild;
}
