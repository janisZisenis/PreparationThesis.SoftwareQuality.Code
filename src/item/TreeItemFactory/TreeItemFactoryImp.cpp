#include "TreeItemFactoryImp.h"
#include <model/HierarchyNode/HierarchyNode.h>
#include <item/HierarchicItem/TreeItem/TreeItem.h>
#include <model/HierarchyNode/AllNodeTypeIncludes.h>
#include <model/HierarchyNode/AllNodeIncludes.h>

#include <item/HierarchicItem/TreeItem/AllTreeItemIncludes.h>

TreeItemFactoryImpPtr TreeItemFactoryImp::getNewInstance() {
    return TreeItemFactoryImpPtr(new TreeItemFactoryImp());
}

TreeItemFactoryImp::~TreeItemFactoryImp() {}

TreeItemFactoryImp::TreeItemFactoryImp() {}

TreeItemPtr TreeItemFactoryImp::makeTreeItem(HierarchyNodePtr node, std::string type) {
    TreeItemPtr item = makeDummyItem(type);

    if(node) {
        if (type == NodeTypes::coordinateSystem()) item = makeCoordinateSystemItem(node);
        else if (type == NodeTypes::pile()) item = makePileItem(node);
        else if (type == NodeTypes::sediment()) item = makeSedimentItem(node);
        else if (type == NodeTypes::water()) item = makeWaterItem(node);
        else if (type == NodeTypes::wave()) item = makeWaveItem(node);

        else if (type == NodeTypes::morison()) item = makeMorisonItem(node);
        else if (type == NodeTypes::sedimentTransport()) item = makeSedimentTransport(node);
        else if (type == NodeTypes::waveDynamic()) item = makeWaveDynamicItem(node);
    }

    return item;
}

TreeItemPtr TreeItemFactoryImp::makeDummyItem(std::string type) {
    return DummyItem::getNewInstance(type, sharedFromThis());
}

TreeItemPtr TreeItemFactoryImp::makeCoordinateSystemItem(HierarchyNodePtr node) {
    CoordinateSystemPtr coordinateSystem = std::dynamic_pointer_cast<CoordinateSystem>(node);
    CoordinateSystemItemPtr coordinateSystemItem = CoordinateSystemItem::getNewInstance(coordinateSystem,
                                                                                        sharedFromThis());
    return coordinateSystemItem;
}

TreeItemPtr TreeItemFactoryImp::makeMorisonItem(HierarchyNodePtr node) {
    MorisonPtr morison = std::dynamic_pointer_cast<Morison>(node);
    MorisonItemPtr morisonItem = MorisonItem::getNewInstance(morison, sharedFromThis());

    morisonItem->setChild(makeTreeItem(morison->getWaveDynamic(), NodeTypes::waveDynamic()), MorisonChildInfo::WAVEDYNAMIC);
    morisonItem->setChild(makeTreeItem(morison->getWaveDynamic(), NodeTypes::pile()), MorisonChildInfo::PILE);
    morisonItem->setChild(makeTreeItem(morison->getWater(), NodeTypes::water()), MorisonChildInfo::WATER);

    return morisonItem;
}

TreeItemPtr TreeItemFactoryImp::makePileItem(HierarchyNodePtr node) {
    PilePtr pile = std::dynamic_pointer_cast<Pile>(node);
    PileItemPtr pileItem = PileItem::getNewInstance(pile, sharedFromThis());

    return pileItem;
}

TreeItemPtr TreeItemFactoryImp::makeSedimentItem(HierarchyNodePtr node) {
    SedimentPtr sediment = std::dynamic_pointer_cast<Sediment>(node);
    SedimentItemPtr sedimentItem = SedimentItem::getNewInstance(sediment, sharedFromThis());

    return sedimentItem;
}

TreeItemPtr TreeItemFactoryImp::makeWaterItem(HierarchyNodePtr node) {
    WaterPtr water = std::dynamic_pointer_cast<Water>(node);
    WaterItemPtr waterItem = WaterItem::getNewInstance(water, sharedFromThis());

    return waterItem;
}

TreeItemPtr TreeItemFactoryImp::makeWaveDynamicItem(HierarchyNodePtr node) {
    WaveDynamicPtr waveDynamic = std::dynamic_pointer_cast<WaveDynamic>(node);
    WaveDynamicItemPtr waveDynamicItem = WaveDynamicItem::getNewInstance(waveDynamic, sharedFromThis());

    waveDynamicItem->setChild(makeTreeItem(waveDynamic->getCoordinateSystem(), NodeTypes::coordinateSystem()),
                              WaveDynamicChildInfo::COORDINATESYSTEM);
    waveDynamicItem->setChild(makeTreeItem(waveDynamic->getWave(), NodeTypes::wave()), WaveDynamicChildInfo::WAVE);

    return waveDynamicItem;
}

TreeItemPtr TreeItemFactoryImp::makeWaveItem(HierarchyNodePtr node) {
    WavePtr wave = std::dynamic_pointer_cast<Wave>(node);
    WaveItemPtr waveItem = WaveItem::getNewInstance(wave, sharedFromThis());

    return waveItem;
}

TreeItemPtr TreeItemFactoryImp::makeSedimentTransport(HierarchyNodePtr node) {
    SedimentTransportPtr sedimentTransport = std::dynamic_pointer_cast<SedimentTransport>(node);
    SedimentTransportItemPtr sedimentTransportItem = SedimentTransportItem::getNewInstance(sedimentTransport,
                                                                                           sharedFromThis());
    sedimentTransportItem->setChild(makeTreeItem(sedimentTransport->getWaveDynamic(), NodeTypes::waveDynamic()), SedimentTransportChildInfo::WAVEDYNAMIC);
    sedimentTransportItem->setChild(makeTreeItem(sedimentTransport->getSediment(), NodeTypes::sediment()), SedimentTransportChildInfo::SEDIMENT);
    sedimentTransportItem->setChild(makeTreeItem(sedimentTransport->getWater(), NodeTypes::water()), SedimentTransportChildInfo::WATER);

    return sedimentTransportItem;
}

TreeItemFactoryImpPtr TreeItemFactoryImp::sharedFromThis() {
    TreeItemFactoryImpPtr me = std::dynamic_pointer_cast<TreeItemFactoryImp>(this->shared_from_this());
    if (!me) throw new SharedFromThisException();
    return me;
}

