#include "MorisonRootBuilder.h"
#include "model/HierarchyNode/Morison/Morison.h"
#include <model/HierarchyNode/Morison/MorisonProperties.h>
#include <item/HierarchicItem/TableItem/TableRoot.h>

#include <model/HierarchyNode/Pile/Pile.h>
#include <model/HierarchyNode/Water/Water.h>
#include <model/HierarchyNode/WaveDynamic/WaveDynamic.h>

MorisonRootBuilderPtr MorisonRootBuilder::getNewInstance(MorisonPtr node) {
    return MorisonRootBuilderPtr(new MorisonRootBuilder(node));
}
MorisonRootBuilder::~MorisonRootBuilder() {}
MorisonRootBuilder::MorisonRootBuilder(MorisonPtr node) : node(node){}

TableItemPtr MorisonRootBuilder::buildRoot() {
    addNodeInfo(node);
    addChildInfo(node->getWaveDynamic(), MorisonProperties::waveDynamic());
    addChildInfo(node->getPile(), MorisonProperties::pile());
    addChildInfo(node->getWater(), MorisonProperties::water());

    return root;
}
