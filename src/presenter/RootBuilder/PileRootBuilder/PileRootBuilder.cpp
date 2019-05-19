#include "PileRootBuilder.h"
#include "model/HierarchyNode/Pile/Pile.h"
#include <model/HierarchyNode/HierarchyNodeProperties.h>
#include <model/HierarchyNode/Pile/PileProperties.h>
#include <item/HierarchicItem/TableItem/TableRoot.h>
#include <model/HierarchyNode/Units.h>

PileRootBuilderPtr PileRootBuilder::getNewInstance(PilePtr node) {
    return PileRootBuilderPtr(new PileRootBuilder(node));
}
PileRootBuilder::~PileRootBuilder() {}
PileRootBuilder::PileRootBuilder(PilePtr node) : node(node){}

TableItemPtr PileRootBuilder::buildRoot() {
    addNodeInfo(node);

    root->appendChild(makeMutableItem(PileProperties::diameter(), std::to_string(node->getDiameter()), Units::meter()));

    return root;
}
