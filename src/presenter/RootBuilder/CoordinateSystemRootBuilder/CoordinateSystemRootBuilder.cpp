#include "CoordinateSystemRootBuilder.h"
#include "model/HierarchyNode/CoordinateSystem/CoordinateSystem.h"
#include <model/HierarchyNode/CoordinateSystem/CoordinateSystemProperties.h>
#include <item/HierarchicItem/TableItem/TableItem.h>
#include <item/HierarchicItem/TableItem/TableRoot.h>
#include <model/HierarchyNode/Units.h>

CoordinateSystemRootBuilderPtr CoordinateSystemRootBuilder::getNewInstance(CoordinateSystemPtr node) {
    return CoordinateSystemRootBuilderPtr(new CoordinateSystemRootBuilder(node));
}
CoordinateSystemRootBuilder::~CoordinateSystemRootBuilder() {}
CoordinateSystemRootBuilder::CoordinateSystemRootBuilder(CoordinateSystemPtr node) : node(node){}

TableItemPtr CoordinateSystemRootBuilder::buildRoot() {
    addNodeInfo(node);

    root->appendChild(makeMutableItem(CoordinateSystemProperties::x(), std::to_string(node->getX()), Units::meter()));
    root->appendChild(makeMutableItem(CoordinateSystemProperties::t(), std::to_string(node->getT()), Units::second()));
    root->appendChild(makeMutableItem(CoordinateSystemProperties::z(), std::to_string(node->getZ()), Units::meter()));

    return root;
}
