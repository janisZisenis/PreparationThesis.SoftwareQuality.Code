#include "HierarchicItem.h"

HierarchicItem::~HierarchicItem() {}

HierarchicItem::HierarchicItem() {}

void HierarchicItem::onBeginInsertChild(const HierarchicItemPtr emiting, const int index) {
	beginInsertChild(emiting, index);
}

void HierarchicItem::onEndInsertChild() {
	endInsertChild();
}

void HierarchicItem::onBeginRemoveChild(const HierarchicItemPtr emiting, const int index) {
    beginRemoveChild(emiting, index);
}

void HierarchicItem::onEndRemoveChild() {
    endRemoveChild();
}

void HierarchicItem::onBeginReplaceChild(const HierarchicItemPtr emiting, const int index) {
    beginReplaceChild(emiting, index);
}

void HierarchicItem::onEndReplaceChild() {
    endReplaceChild();
}

void HierarchicItem::onItemDataChanged(const HierarchicItemPtr item) {
    itemDataChanged(item);
}

bool HierarchicItem::isEditable() {
    return allowEditing;
}

void HierarchicItem::enableEditing() {
    this->allowEditing = true;
}

void HierarchicItem::disableEditing() {
    this->allowEditing = false;
}

HierarchicItemPtr HierarchicItem::getParent() {
    return parent.lock();
}

void HierarchicItem::setParent(HierarchicItemPtr parent){
    this->parent = parent;
}

int HierarchicItem::getRow() {
    if (!this->getParent()) return -1;

    return this->getParent()->childPos(sharedFromThis());
}

void HierarchicItem::connectToChild(HierarchicItemPtr child) {
    if(!child) return;

    child->setParent(sharedFromThis());
    child->beginInsertChild.connect(boost::bind(&HierarchicItem::onBeginInsertChild, this, _1, _2));
    child->endInsertChild.connect(boost::bind(&HierarchicItem::onEndInsertChild, this));
    child->beginRemoveChild.connect(boost::bind(&HierarchicItem::onBeginRemoveChild, this, _1, _2));
    child->endRemoveChild.connect(boost::bind(&HierarchicItem::onEndRemoveChild, this));
    child->beginReplaceChild.connect(boost::bind(&HierarchicItem::onBeginReplaceChild, this, _1, _2));
    child->endReplaceChild.connect(boost::bind(&HierarchicItem::onEndReplaceChild, this));
    child->itemDataChanged.connect(boost::bind(&HierarchicItem::onItemDataChanged, this, _1));
}

void HierarchicItem::disconnectFromChild(HierarchicItemPtr child) {
    if(!child) return;

    child->setParent(nullptr);
    child->beginInsertChild.disconnect(boost::bind(&HierarchicItem::onBeginInsertChild, this, _1, _2));
    child->endInsertChild.disconnect(boost::bind(&HierarchicItem::onEndInsertChild, this));
    child->beginRemoveChild.disconnect(boost::bind(&HierarchicItem::onBeginRemoveChild, this, _1, _2));
    child->endRemoveChild.disconnect(boost::bind(&HierarchicItem::onEndRemoveChild, this));
    child->beginReplaceChild.disconnect(boost::bind(&HierarchicItem::onBeginReplaceChild, this, _1, _2));
    child->endReplaceChild.disconnect(boost::bind(&HierarchicItem::onEndReplaceChild, this));
    child->itemDataChanged.disconnect(boost::bind(&HierarchicItem::onItemDataChanged, this, _1));
}

HierarchicItemPtr HierarchicItem::sharedFromThis() {
    HierarchicItemPtr me = std::dynamic_pointer_cast<HierarchicItem>(this->shared_from_this());
    if (!me) throw new SharedFromThisException();
    return me;
}





