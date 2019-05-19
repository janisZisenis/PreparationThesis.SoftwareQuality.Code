#include "CoordinateSystemItem.h"

#include "model/HierarchyNode/CoordinateSystem/CoordinateSystem.h"
#include <item/TreeItemFactory/TreeItemFactory.h>

CoordinateSystemItemPtr CoordinateSystemItem::getNewInstance(CoordinateSystemPtr node, TreeItemFactoryPtr itemFactoryService) {
    return CoordinateSystemItemPtr(new CoordinateSystemItem(node, itemFactoryService));
}
CoordinateSystemItem::~CoordinateSystemItem() {
	disconnectFromNode(node);
}
CoordinateSystemItem::CoordinateSystemItem(CoordinateSystemPtr node, TreeItemFactoryPtr itemFactoryService) : TreeItem(itemFactoryService) , node(node){
    connectToNode(node);
}

int CoordinateSystemItem::getChildCount() {
    return CoordinateSystemChildInfo::NUMBER_OF_CHILDS;
}
HierarchicItemPtr CoordinateSystemItem::getChildAt(int row) {
    return nullptr;
}

std::string CoordinateSystemItem::getType() {
    return node->getType();
}
std::string CoordinateSystemItem::getName() {
    return node->getName();
}

HierarchyNodePtr CoordinateSystemItem::getNode() {
    return this->node;
}

int CoordinateSystemItem::childPos(HierarchicItemPtr child) {
    return CoordinateSystemChildInfo::INVALID;
}

CoordinateSystemItemPtr CoordinateSystemItem::sharedFromThis() {
    CoordinateSystemItemPtr me = std::dynamic_pointer_cast<CoordinateSystemItem>(this->shared_from_this());
    if (!me) throw new SharedFromThisException();
    return me;
}
