#include <item/TreeItemFactory/TreeItemFactory.h>

#include "PileItem.h"
#include "model/HierarchyNode/Pile/Pile.h"

PileItemPtr PileItem::getNewInstance(PilePtr node, TreeItemFactoryPtr itemFactory) {
	return PileItemPtr(new PileItem(node, itemFactory));
}
PileItem::~PileItem() {
	disconnectFromNode(node);
}
PileItem::PileItem(PilePtr node, TreeItemFactoryPtr itemFactory) : TreeItem(itemFactory), node(node) {
	connectToNode(node);
}

int PileItem::getChildCount() {
	return PileChildInfo::NUMBER_OF_CHILDS;
}
HierarchicItemPtr PileItem::getChildAt(int row) {
	return nullptr;
}

std::string PileItem::getName() {
	return node->getName();
}
std::string PileItem::getType() {
	return node->getType();
}

HierarchyNodePtr PileItem::getNode() {
	return this->node;
}

int PileItem::childPos(HierarchicItemPtr child) {
	return PileChildInfo::INVALID;
}

PileItemPtr PileItem::sharedFromThis() {
	PileItemPtr me = std::dynamic_pointer_cast<PileItem>(this->shared_from_this());
	if (!me) throw new SharedFromThisException();
	return me;
}