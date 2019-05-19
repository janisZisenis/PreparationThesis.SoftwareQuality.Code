#include "WaterRootBuilder.h"
#include "model/HierarchyNode/Water/Water.h"
#include <model/HierarchyNode/HierarchyNodeProperties.h>
#include <model/HierarchyNode/Water/WaterProperties.h>
#include <item/HierarchicItem/TableItem/TableRoot.h>
#include <model/HierarchyNode/Units.h>

WaterRootBuilderPtr WaterRootBuilder::getNewInstance(WaterPtr node) {
    return WaterRootBuilderPtr(new WaterRootBuilder(node));
}
WaterRootBuilder::~WaterRootBuilder() {}
WaterRootBuilder::WaterRootBuilder(WaterPtr node) : node(node){}

TableItemPtr WaterRootBuilder::buildRoot() {
    addNodeInfo(node);

    root->appendChild(makeMutableItem(WaterProperties::density(), std::to_string(node->getDensity()), Units::density()));
    root->appendChild(makeMutableItem(WaterProperties::viscosity(), std::to_string(node->getViscosity()), Units::viscosity()));

    return root;
}
