#include "SedimentRootBuilder.h"
#include "model/HierarchyNode/Sediment/Sediment.h"
#include <model/HierarchyNode/HierarchyNodeProperties.h>
#include <model/HierarchyNode/Sediment/SedimentProperties.h>
#include <item/HierarchicItem/TableItem/TableRoot.h>
#include <model/HierarchyNode/Units.h>

SedimentRootBuilderPtr SedimentRootBuilder::getNewInstance(SedimentPtr node) {
    return SedimentRootBuilderPtr(new SedimentRootBuilder(node));
}
SedimentRootBuilder::~SedimentRootBuilder() {}
SedimentRootBuilder::SedimentRootBuilder(SedimentPtr node) : node(node){}

TableItemPtr SedimentRootBuilder::buildRoot() {
    addNodeInfo(node);

    root->appendChild(makeMutableItem(SedimentProperties::density(), std::to_string(node->getDensity()), Units::density()));

    return root;
}
