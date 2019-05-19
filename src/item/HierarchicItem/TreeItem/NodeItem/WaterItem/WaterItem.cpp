#include "WaterItem.h"
#include <item/TreeItemFactory/TreeItemFactory.h>
#include "model/HierarchyNode/Water/Water.h"

WaterItemPtr WaterItem::getNewInstance(WaterPtr node, TreeItemFactoryPtr itemFactory) {
    return WaterItemPtr(new WaterItem(node, itemFactory));
}

WaterItem::~WaterItem() {
    disconnectFromNode(node);
}

WaterItem::WaterItem(WaterPtr node, TreeItemFactoryPtr itemFactory) : TreeItem(itemFactory), node(node) {
    connectToNode(node);
}

int WaterItem::getChildCount() {
    return WaterChildInfo::NUMBER_OF_CHILDS;
}

HierarchicItemPtr WaterItem::getChildAt(int row) {
    return nullptr;
}

std::string WaterItem::getName() {
    return node->getName();
}

std::string WaterItem::getType() {
    return node->getType();
}

HierarchyNodePtr WaterItem::getNode() {
    return this->node;
}

int WaterItem::childPos(HierarchicItemPtr child) {
    return WaterChildInfo::INVALID;
}

WaterItemPtr WaterItem::sharedFromThis() {
    WaterItemPtr me = std::dynamic_pointer_cast<WaterItem>(this->shared_from_this());
    if (!me) throw new SharedFromThisException();
    return me;
}
