#include "TreeItem.h"
#include <item/TreeItemFactory/TreeItemFactory.h>
#include <model/HierarchyNode/HierarchyNode.h>

TreeItem::~TreeItem() {}
TreeItem::TreeItem(TreeItemFactoryPtr itemFactory) : HierarchicItem(), itemFactory(itemFactory) {}

void TreeItem::onChildNodeInserted(const HierarchyNodePtr inserted, const int index) {}
void TreeItem::onChildNodeRemoved(const HierarchyNodePtr removed, const int index) {}
void TreeItem::onChildNodeReplaced(const HierarchyNodePtr newChild, const std::string type) {}
void TreeItem::onNodeChanged(const HierarchyNodePtr changed) {
    itemDataChanged(sharedFromThis());
}

void TreeItem::connectToNode(HierarchyNodePtr node) {
    if(!node) return;

    node->childInserted.connect(boost::bind(&TreeItem::onChildNodeInserted, this, _1, _2));
    node->childRemoved.connect(boost::bind(&TreeItem::onChildNodeRemoved, this, _1, _2));
    node->childReplaced.connect(boost::bind(&TreeItem::onChildNodeReplaced, this, _1, _2));
    node->nodeChanged.connect(boost::bind(&TreeItem::onNodeChanged, this, _1));}

void TreeItem::disconnectFromNode(HierarchyNodePtr node) {
    if(!node) return;

    node->childInserted.disconnect(boost::bind(&TreeItem::onChildNodeInserted, this, _1, _2));
    node->childRemoved.disconnect(boost::bind(&TreeItem::onChildNodeRemoved, this, _1, _2));
    node->childReplaced.disconnect(boost::bind(&TreeItem::onChildNodeReplaced, this, _1, _2));
    node->nodeChanged.disconnect(boost::bind(&TreeItem::onNodeChanged, this, _1));
}

TreeItemPtr TreeItem::sharedFromThis() {
    TreeItemPtr me = std::dynamic_pointer_cast<TreeItem>(this->shared_from_this());
    if(!me) throw new SharedFromThisException();
    return me;
}