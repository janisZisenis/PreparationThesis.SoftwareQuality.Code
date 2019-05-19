#include "SedimentBinder.h"
#include "model/HierarchyNode/SedimentTransport/SedimentTransport.h"

#include "model/HierarchyNode/Sediment/Sediment.h"

SedimentBinderPtr SedimentBinder::getNewInstance(SedimentPtr node) {
    return SedimentBinderPtr(new SedimentBinder(node));
}

SedimentBinder::~SedimentBinder() {}

SedimentBinder::SedimentBinder(SedimentPtr node) : child(node) {}

void SedimentBinder::visit(SedimentTransportPtr sedimentTransport) {
    SedimentPtr oldChild = sedimentTransport->getSediment();

    sedimentTransport->setSediment(child);

    this->child = oldChild;
}
