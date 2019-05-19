#include "MorisonItem.h"
#include <item/TreeItemFactory/TreeItemFactory.h>

#include <model/HierarchyNode/Morison/Morison.h>
#include <model/HierarchyNode/Morison/MorisonProperties.h>

MorisonItemPtr MorisonItem::getNewInstance(MorisonPtr node, TreeItemFactoryPtr itemFactory) {
    return MorisonItemPtr(new MorisonItem(node, itemFactory));
}

MorisonItem::~MorisonItem() {
    disconnectFromNode(node);
}

MorisonItem::MorisonItem(MorisonPtr node, TreeItemFactoryPtr itemFactory) : TreeItem(itemFactory), node(node) {
    connectToNode(node);
}

void MorisonItem::onChildNodeReplaced(const HierarchyNodePtr newChild, const std::string type) {
    setChild(itemFactory->makeTreeItem(newChild, type), getChildIndex(type));
}

HierarchicItemPtr MorisonItem::getChildAt(int row) {
	if (row <= MorisonChildInfo::INVALID || row >= MorisonChildInfo::NUMBER_OF_CHILDS)
		return nullptr;
    return items[row];
}

void MorisonItem::setChild(HierarchicItemPtr child, MorisonChildInfo type) {
    beginReplaceChild(sharedFromThis(), type);
        disconnectFromChild(items[type]);
        connectToChild(child);
        items[type] = child;
    endReplaceChild();
}

int MorisonItem::getChildCount() {
    return MorisonChildInfo::NUMBER_OF_CHILDS;
}

int MorisonItem::childPos(HierarchicItemPtr child) {
    if (child == items[MorisonChildInfo::WAVEDYNAMIC]) return MorisonChildInfo::WAVEDYNAMIC;
    if (child == items[MorisonChildInfo::PILE]) return MorisonChildInfo::PILE;
    if (child == items[MorisonChildInfo::WATER]) return MorisonChildInfo::WATER;
    else return MorisonChildInfo::INVALID;
}

std::string MorisonItem::getName() {
    return node->getName();
}

std::string MorisonItem::getType() {
    return node->getType();
}

HierarchyNodePtr MorisonItem::getNode() {
    return node;
}

MorisonChildInfo MorisonItem::getChildIndex(std::string roleName) {
    if (roleName == MorisonProperties::waveDynamic()) return MorisonChildInfo::WAVEDYNAMIC;
    if (roleName == MorisonProperties::pile()) return MorisonChildInfo::PILE;
    if (roleName == MorisonProperties::water()) return MorisonChildInfo::WATER;
    return MorisonChildInfo::INVALID;
}

MorisonItemPtr MorisonItem::sharedFromThis() {
    MorisonItemPtr me = std::dynamic_pointer_cast<MorisonItem>(this->shared_from_this());
    if (!me) throw new SharedFromThisException();
    return me;
}

