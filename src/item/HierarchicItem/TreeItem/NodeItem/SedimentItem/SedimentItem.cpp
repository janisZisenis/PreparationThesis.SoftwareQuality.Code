#include "SedimentItem.h"
#include "model/HierarchyNode/Sediment/Sediment.h"
#include <item/TreeItemFactory/TreeItemFactory.h>

SedimentItemPtr SedimentItem::getNewInstance(SedimentPtr node, TreeItemFactoryPtr itemFactory)
{
	return SedimentItemPtr(new SedimentItem(node, itemFactory));
}
SedimentItem::~SedimentItem() {
	disconnectFromNode(node);
}
SedimentItem::SedimentItem(SedimentPtr node, TreeItemFactoryPtr itemFactory) : TreeItem(itemFactory), node(node){
	connectToNode(node);
}

int SedimentItem::getChildCount() {
	return SedimentChildInfo::NUMBER_OF_CHILDS;
}
HierarchicItemPtr SedimentItem::getChildAt(int row) {
	return nullptr;
}

std::string SedimentItem::getName() {
	return node->getName();
}
std::string SedimentItem::getType() {
	return node->getType();
}

HierarchyNodePtr SedimentItem::getNode() {
	return this->node;
}

int SedimentItem::childPos(HierarchicItemPtr child) {
	return SedimentChildInfo::INVALID;
}

SedimentItemPtr SedimentItem::sharedFromThis() {
	SedimentItemPtr me = std::dynamic_pointer_cast<SedimentItem>(this->shared_from_this());
	if (!me) throw new SharedFromThisException();
	return me;
}
