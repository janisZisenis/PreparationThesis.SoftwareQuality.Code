#include "SedimentTransportRootBuilder.h"
#include "model/HierarchyNode/SedimentTransport/SedimentTransport.h"
#include <model/HierarchyNode/SedimentTransport/SedimentTransportProperties.h>
#include <item/HierarchicItem/TableItem/TableRoot.h>

#include <model/HierarchyNode/Water/Water.h>
#include <model/HierarchyNode/Sediment/Sediment.h>
#include <model/HierarchyNode/WaveDynamic/WaveDynamic.h>

SedimentTransportRootBuilderPtr SedimentTransportRootBuilder::getNewInstance(SedimentTransportPtr node) {
    return SedimentTransportRootBuilderPtr(new SedimentTransportRootBuilder(node));
}
SedimentTransportRootBuilder::~SedimentTransportRootBuilder() {}
SedimentTransportRootBuilder::SedimentTransportRootBuilder(SedimentTransportPtr node) : node(node){}

TableItemPtr SedimentTransportRootBuilder::buildRoot() {
    addNodeInfo(node);
    addChildInfo(node->getWaveDynamic(), SedimentTransportProperties::waveDynamic());
    addChildInfo(node->getSediment(), SedimentTransportProperties::sediment());
    addChildInfo(node->getWater(), SedimentTransportProperties::water());

    return root;
}
