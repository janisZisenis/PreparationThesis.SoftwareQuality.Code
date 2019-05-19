#include "RootBuilderFactoryImp.h"

#include <model/HierarchyNode/AllNodeTypeIncludes.h>
#include <model/HierarchyNode/AllNodeIncludes.h>
#include <presenter/RootBuilder/AllRootBuilderIncludes.h>

RootBuilderFactoryImpPtr RootBuilderFactoryImp::getNewInstance() {
    return RootBuilderFactoryImpPtr(new RootBuilderFactoryImp());
}
RootBuilderFactoryImp::~RootBuilderFactoryImp() {}
RootBuilderFactoryImp::RootBuilderFactoryImp() {}

RootBuilderPtr RootBuilderFactoryImp::makeRootBuilder(HierarchyNodePtr node) {
    if(!node) return makeEmptyRootBuilder();

    if (node->getType() == "") return makeEmptyRootBuilder();
    if (node->getType() == NodeTypes::coordinateSystem()) return makeCoordinateSystemRootBuilder(node);
    if (node->getType() == NodeTypes::morison()) return makeMorisonRootBuilder(node);
    if (node->getType() == NodeTypes::pile()) return makePileRootBuilder(node);
    if (node->getType() == NodeTypes::sediment()) return makeSedimentRootBuilder(node);
    if (node->getType() == NodeTypes::sedimentTransport()) return makeSedimentTransportRootBuilder(node);
    if (node->getType() == NodeTypes::water()) return makeWaterRootBuilder(node);
    if (node->getType() == NodeTypes::waveDynamic()) return makeWaveDynamicRootBuilder(node);
    if (node->getType() == NodeTypes::wave()) return makeWaveRootBuilder(node);

    else return makeDefaultRootBuilder(node);
}

RootBuilderPtr RootBuilderFactoryImp::makeCoordinateSystemRootBuilder(HierarchyNodePtr node) {
    CoordinateSystemPtr coordinateSystem = std::dynamic_pointer_cast<CoordinateSystem>(node);
    return CoordinateSystemRootBuilder::getNewInstance(coordinateSystem);
}

RootBuilderPtr RootBuilderFactoryImp::makeMorisonRootBuilder(HierarchyNodePtr node) {
    MorisonPtr morison = std::dynamic_pointer_cast<Morison>(node);
    return MorisonRootBuilder::getNewInstance(morison);
}

RootBuilderPtr RootBuilderFactoryImp::makePileRootBuilder(HierarchyNodePtr node) {
    PilePtr pile = std::dynamic_pointer_cast<Pile>(node);
    return PileRootBuilder::getNewInstance(pile);
}

RootBuilderPtr RootBuilderFactoryImp::makeSedimentRootBuilder(HierarchyNodePtr node) {
    SedimentPtr sediment = std::dynamic_pointer_cast<Sediment>(node);
    return SedimentRootBuilder::getNewInstance(sediment);
}

RootBuilderPtr RootBuilderFactoryImp::makeSedimentTransportRootBuilder(HierarchyNodePtr node) {
    SedimentTransportPtr sedimentTransport = std::dynamic_pointer_cast<SedimentTransport>(node);
    return SedimentTransportRootBuilder::getNewInstance(sedimentTransport);
}

RootBuilderPtr RootBuilderFactoryImp::makeWaterRootBuilder(HierarchyNodePtr node) {
    WaterPtr water = std::dynamic_pointer_cast<Water>(node);
    return WaterRootBuilder::getNewInstance(water);
}

RootBuilderPtr RootBuilderFactoryImp::makeWaveDynamicRootBuilder(HierarchyNodePtr node) {
    WaveDynamicPtr waveDynamic = std::dynamic_pointer_cast<WaveDynamic>(node);
    return WaveDynamicRootBuilder::getNewInstance(waveDynamic);
}

RootBuilderPtr RootBuilderFactoryImp::makeWaveRootBuilder(HierarchyNodePtr node) {
    WavePtr wave = std::dynamic_pointer_cast<Wave>(node);
    return WaveRootBuilder::getNewInstance(wave);
}

RootBuilderPtr RootBuilderFactoryImp::makeEmptyRootBuilder() {
    return RootBuilder::getNewInstance();
}

RootBuilderPtr RootBuilderFactoryImp::makeDefaultRootBuilder(HierarchyNodePtr node) {
    return DefaultRootBuilder::getNewInstance(node);
}

