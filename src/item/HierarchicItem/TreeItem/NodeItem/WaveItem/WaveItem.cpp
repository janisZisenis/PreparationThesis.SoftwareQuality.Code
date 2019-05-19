#include "WaveItem.h"
#include <item/TreeItemFactory/TreeItemFactory.h>
#include "model/HierarchyNode/Wave/Wave.h"

WaveItemPtr WaveItem::getNewInstance(WavePtr node, TreeItemFactoryPtr itemFactory) {
	return WaveItemPtr(new WaveItem(node, itemFactory));
}
WaveItem::~WaveItem() {
	disconnectFromNode(node);
}
WaveItem::WaveItem(WavePtr node, TreeItemFactoryPtr itemFactory) : TreeItem(itemFactory), node(node) {
	connectToNode(node);
}

int WaveItem::getChildCount() {
	return WaveChildInfo::NUMBER_OF_CHILDS;
}
HierarchicItemPtr WaveItem::getChildAt(int row) {
	return nullptr;
}

std::string WaveItem::getName() {
	return node->getName();
}
std::string WaveItem::getType() {
	return node->getType();
}

HierarchyNodePtr WaveItem::getNode() {
	return this->node;
}

int WaveItem::childPos(HierarchicItemPtr child) {
	return WaveChildInfo::INVALID;
}

WaveItemPtr WaveItem::sharedFromThis() {
	WaveItemPtr me = std::dynamic_pointer_cast<WaveItem>(this->shared_from_this());
	if (!me) throw new SharedFromThisException();
	return me;
}
