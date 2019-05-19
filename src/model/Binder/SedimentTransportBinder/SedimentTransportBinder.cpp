#include "SedimentTransportBinder.h"
#include "model/HierarchyNode/SedimentTransport/SedimentTransport.h"

SedimentTransportBinderPtr SedimentTransportBinder::getNewInstance(SedimentTransportPtr node) {
    return SedimentTransportBinderPtr(new SedimentTransportBinder(node));
}

SedimentTransportBinder::~SedimentTransportBinder() {}

SedimentTransportBinder::SedimentTransportBinder(SedimentTransportPtr node) : child(node) {}

