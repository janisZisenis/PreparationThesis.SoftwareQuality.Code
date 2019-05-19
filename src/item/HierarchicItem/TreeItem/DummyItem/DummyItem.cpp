#include "DummyItem.h"
#include <item/TreeItemFactory/TreeItemFactory.h>
#include <model/HierarchyNode/HierarchyNodeProperties.h>
#include <model/HierarchyNode/HierarchyNode.h>

DummyItemPtr DummyItem::getNewInstance(std::string type, TreeItemFactoryPtr itemFactory) {
	return DummyItemPtr(new DummyItem(type, itemFactory));
}
DummyItem::~DummyItem() {}
DummyItem::DummyItem(std::string type, TreeItemFactoryPtr itemFactory) : TreeItem(itemFactory), type(type) {
	this->disableEditing();
}

std::string DummyItem::getType() {
	return this->type;
}

std::string DummyItem::getName() {
	return HierarchyNodeProperties::emptyChild();
}

int DummyItem::getChildCount() {
	return 0;
}

HierarchicItemPtr DummyItem::getChildAt(int row) {
	return nullptr;
}

int DummyItem::childPos(HierarchicItemPtr child) {
	return -1;
}

DummyItemPtr DummyItem::sharedFromThis() {
	DummyItemPtr me = std::dynamic_pointer_cast<DummyItem>(this->shared_from_this());
	if (!me) throw new SharedFromThisException();
	return me;
}

HierarchyNodePtr DummyItem::getNode() {
	return nullptr;
}
