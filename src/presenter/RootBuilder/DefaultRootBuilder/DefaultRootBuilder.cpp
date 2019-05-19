#include "DefaultRootBuilder.h"
#include <model/HierarchyNode/HierarchyNode.h>
#include <model/HierarchyNode/HierarchyNodeProperties.h>
#include <item/HierarchicItem/TableItem/TableRoot.h>

DefaultRootBuilderPtr DefaultRootBuilder::getNewInstance(HierarchyNodePtr node) {
    return DefaultRootBuilderPtr(new DefaultRootBuilder(node));
}
DefaultRootBuilder::~DefaultRootBuilder() {}
DefaultRootBuilder::DefaultRootBuilder(HierarchyNodePtr node) : node(node) {}

TableItemPtr DefaultRootBuilder::buildRoot() {
    addNodeInfo(node);
    return root;
}

