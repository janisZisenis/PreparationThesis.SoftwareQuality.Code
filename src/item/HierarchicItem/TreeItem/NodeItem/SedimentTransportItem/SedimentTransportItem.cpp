#include "SedimentTransportItem.h"
#include <item/TreeItemFactory/TreeItemFactory.h>

#include "model/HierarchyNode/SedimentTransport/SedimentTransport.h"
#include "model/HierarchyNode/SedimentTransport/SedimentTransportProperties.h"

SedimentTransportItemPtr SedimentTransportItem::getNewInstance(SedimentTransportPtr node, TreeItemFactoryPtr itemFactory) {
	return SedimentTransportItemPtr(new SedimentTransportItem(node, itemFactory));
}

SedimentTransportItem::~SedimentTransportItem() {
	disconnectFromNode(node);
}
SedimentTransportItem::SedimentTransportItem(SedimentTransportPtr node, TreeItemFactoryPtr itemFactory) : TreeItem(itemFactory), node(node) {
	connectToNode(node);
}

void SedimentTransportItem::onChildNodeReplaced(const std::shared_ptr<HierarchyNode> newChild, const std::string type) {
	setChild(itemFactory->makeTreeItem(newChild, type), getChildIndex(type));
}

HierarchicItemPtr SedimentTransportItem::getChildAt(int row) {
	if (row <= SedimentTransportChildInfo::INVALID || row >= SedimentTransportChildInfo::NUMBER_OF_CHILDS)
		return nullptr;
	return items[row];
}

void SedimentTransportItem::setChild(HierarchicItemPtr child, SedimentTransportChildInfo type) {
	beginReplaceChild(sharedFromThis(), type);
		disconnectFromChild(items[type]);
		connectToChild(child);
		items[type] = child;
	endReplaceChild();
}

int SedimentTransportItem::getChildCount() {
	return SedimentTransportChildInfo::NUMBER_OF_CHILDS;
}

std::string SedimentTransportItem::getType() {
	return this->node->getType();
}
std::string SedimentTransportItem::getName(){
	return this->node->getName();
}

HierarchyNodePtr SedimentTransportItem::getNode()
{
	return this->node;
}

int SedimentTransportItem::childPos(HierarchicItemPtr child)
{
	if (child == items[SedimentTransportChildInfo::WAVEDYNAMIC]) return SedimentTransportChildInfo::WAVEDYNAMIC;
	if (child == items[SedimentTransportChildInfo::SEDIMENT]) return SedimentTransportChildInfo::SEDIMENT;
	if (child == items[SedimentTransportChildInfo::WATER]) return SedimentTransportChildInfo::WATER;
	else return SedimentTransportChildInfo::INVALID;
}

SedimentTransportChildInfo SedimentTransportItem::getChildIndex(std::string roleName)
{
	if (roleName == SedimentTransportProperties::waveDynamic()) return SedimentTransportChildInfo::WAVEDYNAMIC;
	if (roleName == SedimentTransportProperties::sediment()) return SedimentTransportChildInfo::SEDIMENT;
	if (roleName == SedimentTransportProperties::water()) return SedimentTransportChildInfo::WATER;
	return SedimentTransportChildInfo::INVALID;
}

SedimentTransportItemPtr SedimentTransportItem::sharedFromThis()
{
	SedimentTransportItemPtr me = std::dynamic_pointer_cast<SedimentTransportItem>(this->shared_from_this());
	if (!me) throw new SharedFromThisException();
	return me;
}

