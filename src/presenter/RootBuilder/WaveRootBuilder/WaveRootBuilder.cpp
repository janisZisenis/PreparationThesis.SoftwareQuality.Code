#include "WaveRootBuilder.h"
#include <model/HierarchyNode/Units.h>

#include "model/HierarchyNode/Wave/Wave.h"
#include <model/HierarchyNode/Wave/WaveProperties.h>
#include <item/HierarchicItem/TableItem/TableRoot.h>

WaveRootBuilderPtr WaveRootBuilder::getNewInstance(WavePtr node) {
    return WaveRootBuilderPtr(new WaveRootBuilder(node));
}
WaveRootBuilder::~WaveRootBuilder() {}
WaveRootBuilder::WaveRootBuilder(WavePtr node) : node(node){}

TableItemPtr WaveRootBuilder::buildRoot() {
    addNodeInfo(node);

    root->appendChild(makeMutableItem(WaveProperties::waterDepth(), std::to_string(node->getWaterDepth()),  Units::meter()));
    root->appendChild(makeMutableItem(WaveProperties::waveHeight(), std::to_string(node->getHeight()), Units::meter()));
    root->appendChild(makeMutableItem(WaveProperties::waveLength(), std::to_string(node->getLength()), Units::meter()));
    root->appendChild(makeMutableItem(WaveProperties::wavePeriod(), std::to_string(node->getPeriod()), Units::second()));

    return root;
}
