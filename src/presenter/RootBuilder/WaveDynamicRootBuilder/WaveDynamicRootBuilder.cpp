#include "WaveDynamicRootBuilder.h"
#include "model/HierarchyNode/WaveDynamic/WaveDynamic.h"
#include "model/HierarchyNode/WaveDynamic/WaveDynamicChildTypes.h"
#include <model/HierarchyNode/HierarchyNodeProperties.h>
#include <model/HierarchyNode/WaveDynamic/WaveDynamicProperties.h>
#include <item/HierarchicItem/TableItem/TableRoot.h>

#include <model/HierarchyNode/CoordinateSystem/CoordinateSystem.h>
#include <model/HierarchyNode/Wave/Wave.h>

WaveDynamicRootBuilderPtr WaveDynamicRootBuilder::getNewInstance(WaveDynamicPtr node) {
    return WaveDynamicRootBuilderPtr(new WaveDynamicRootBuilder(node));
}
WaveDynamicRootBuilder::~WaveDynamicRootBuilder() {}
WaveDynamicRootBuilder::WaveDynamicRootBuilder(WaveDynamicPtr node) : node(node){}

TableItemPtr WaveDynamicRootBuilder::buildRoot() {
    addNodeInfo(node);
    addChildInfo(node->getCoordinateSystem(), WaveDynamicProperties::coordinateSystem());
    addChildInfo(node->getWave(), WaveDynamicProperties::wave());

    return root;
}
