#include "WaveDynamicItem.h"
#include <item/TreeItemFactory/TreeItemFactory.h>
#include "model/HierarchyNode/WaveDynamic/WaveDynamic.h"
#include "model/HierarchyNode/WaveDynamic/WaveDynamicProperties.h"

#include "model/HierarchyNode/CoordinateSystem/CoordinateSystem.h"
#include "model/HierarchyNode/Water/Water.h"
#include "model/HierarchyNode/Wave/Wave.h"

WaveDynamicItemPtr WaveDynamicItem::getNewInstance(WaveDynamicPtr node, TreeItemFactoryPtr itemFactory) {
	return WaveDynamicItemPtr(new WaveDynamicItem(node, itemFactory));
}
WaveDynamicItem::~WaveDynamicItem() {
	disconnectFromNode(node);
}
WaveDynamicItem::WaveDynamicItem(WaveDynamicPtr node, TreeItemFactoryPtr itemFactory) : TreeItem(itemFactory), node(node) {
	connectToNode(node);
}

void WaveDynamicItem::onChildNodeReplaced(const std::shared_ptr<HierarchyNode> newChild, const std::string type) {
	setChild(itemFactory->makeTreeItem(newChild, type), getChildIndex(type));
}

HierarchicItemPtr WaveDynamicItem::getChildAt(int row) {
	if (row <= WaveDynamicChildInfo::INVALID || row >= WaveDynamicChildInfo::NUMBER_OF_CHILDS)
		return nullptr; 
	return items[row];
}
void WaveDynamicItem::setChild(HierarchicItemPtr child, WaveDynamicChildInfo type) {
	beginReplaceChild(sharedFromThis(), type);
		disconnectFromChild(items[type]);
		connectToChild(child);
		items[type] = child;
	endReplaceChild();
}
int WaveDynamicItem::getChildCount() {
	return WaveDynamicChildInfo::NUMBER_OF_CHILDS;
}

std::string WaveDynamicItem::getName() {
	return node->getName();
}
std::string WaveDynamicItem::getType() {
	return node->getType();
}

HierarchyNodePtr WaveDynamicItem::getNode() {
	return node;
}

int WaveDynamicItem::childPos(HierarchicItemPtr child) {
	if (child == items[WaveDynamicChildInfo::COORDINATESYSTEM]) return WaveDynamicChildInfo::COORDINATESYSTEM;
	if (child == items[WaveDynamicChildInfo::WAVE]) return WaveDynamicChildInfo::WAVE;
	else return WaveDynamicChildInfo::INVALID;
}

WaveDynamicChildInfo WaveDynamicItem::getChildIndex(std::string roleName) {
	if (roleName == WaveDynamicProperties::coordinateSystem()) return WaveDynamicChildInfo::COORDINATESYSTEM;
	if (roleName == WaveDynamicProperties::wave()) return WaveDynamicChildInfo::WAVE;
	return WaveDynamicChildInfo::INVALID;
}

WaveDynamicItemPtr WaveDynamicItem::sharedFromThis() {
	WaveDynamicItemPtr me = std::dynamic_pointer_cast<WaveDynamicItem>(this->shared_from_this());
	if (!me) throw new SharedFromThisException();
	return me;
}

