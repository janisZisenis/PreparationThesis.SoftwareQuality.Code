#include <item/HierarchicItem/TreeItem/TreeItem.h>
#include "MyQItemTreeModel.h"
#include <model/HierarchyNode/AllNodeTypeIncludes.h>
#include <QColor>

MyQItemTreeModel::MyQItemTreeModel(TreeItemPtr root) : MyQItemModel(root) {
    connectTo(root);
}
MyQItemTreeModel::~MyQItemTreeModel() {
    TreeItemPtr myRoot = std::dynamic_pointer_cast<TreeItem>(root);
    disconnectFrom(myRoot);
}

void MyQItemTreeModel::onBeginInsertItem(HierarchicItemPtr parent, int index) {
    beginInsertRows(getIndex(parent), index, index);
}

void MyQItemTreeModel::onEndInsertItem() {
    this->endInsertRows();
}

void MyQItemTreeModel::onBeginRemoveItem(HierarchicItemPtr parent, int index) {
    beginRemoveRows(getIndex(parent), index, index);
}

void MyQItemTreeModel::onEndRemoveItem() {
    this->endRemoveRows();
}

void MyQItemTreeModel::onBeginReplaceItem(HierarchicItemPtr parent, int index) {
    this->onBeginRemoveItem(parent, index);
    this->onEndRemoveItem();
    this->onBeginInsertItem(parent, index);
}

void MyQItemTreeModel::onEndReplaceItem() {
    this->onEndInsertItem();
}

void MyQItemTreeModel::onItemDataChanged(HierarchicItemPtr item) {
    emit QAbstractItemModel::dataChanged(getIndex(item), getIndex(item));
}

QVariant MyQItemTreeModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole) {
        if (section == 0) return "Name";
        if (section == 1) return "Type";
    }
    return QVariant();
}

Qt::ItemFlags MyQItemTreeModel::flags(const QModelIndex &index) const {
    TreeItem* item = dynamic_cast<TreeItem*>(getItem(index));
    if (!item || !item->isEditable()) 
		return Qt::NoItemFlags;
	if (index.column() == 0 && item->isEditable())
        return QAbstractItemModel::flags(index) |= Qt::ItemIsEditable;
    else
        return QAbstractItemModel::flags(index);
}

void MyQItemTreeModel::connectTo(TreeItemPtr myRoot) {
    myRoot->beginInsertChild.connect(boost::bind(&MyQItemTreeModel::onBeginInsertItem, this, _1, _2));
    myRoot->endInsertChild.connect(boost::bind(&MyQItemTreeModel::onEndInsertItem, this));
    myRoot->beginRemoveChild.connect(boost::bind(&MyQItemTreeModel::onBeginRemoveItem, this, _1, _2));
    myRoot->endRemoveChild.connect(boost::bind(&MyQItemTreeModel::onEndRemoveItem, this));
    myRoot->beginReplaceChild.connect(boost::bind(&MyQItemTreeModel::onBeginReplaceItem, this, _1, _2));
    myRoot->endReplaceChild.connect(boost::bind(&MyQItemTreeModel::onEndReplaceItem, this));
    myRoot->itemDataChanged.connect(boost::bind(&MyQItemTreeModel::onItemDataChanged, this, _1));
}

void MyQItemTreeModel::disconnectFrom(TreeItemPtr myRoot) {
    myRoot->beginInsertChild.disconnect(boost::bind(&MyQItemTreeModel::onBeginInsertItem, this, _1, _2));
    myRoot->endInsertChild.disconnect(boost::bind(&MyQItemTreeModel::onEndInsertItem, this));
    myRoot->beginRemoveChild.disconnect(boost::bind(&MyQItemTreeModel::onBeginRemoveItem, this, _1, _2));
    myRoot->endRemoveChild.disconnect(boost::bind(&MyQItemTreeModel::onEndRemoveItem, this));
    myRoot->beginRemoveChild.disconnect(boost::bind(&MyQItemTreeModel::onBeginReplaceItem, this, _1, _2));
    myRoot->endRemoveChild.disconnect(boost::bind(&MyQItemTreeModel::onEndReplaceItem, this));
    myRoot->itemDataChanged.disconnect(boost::bind(&MyQItemTreeModel::onItemDataChanged, this, _1));
}

QVariant MyQItemTreeModel::getDataAt(HierarchicItem* item, int role, int col) const {
    TreeItem* treeItem = dynamic_cast<TreeItem*>(item);
    if(!treeItem) return QVariant();

	if (role == Qt::DecorationRole && col == 0)
		return getIcon(treeItem->getType());

    if (role == Qt::DisplayRole) {
        if (col == 0) return QString::fromStdString(treeItem->getName());
        if (col == 1) return QString::fromStdString(treeItem->getType());
    }

    return QVariant();
}

bool MyQItemTreeModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    if (role != Qt::EditRole)
        return false;

    TreeItem *item = dynamic_cast<TreeItem*>(getItem(index));
    if(!item) return false;

    this->itemEdited(value.toString().toStdString());

    return false;
}

QVariant MyQItemTreeModel::getIcon(std::string type) const {
	if (type == NodeTypes::coordinateSystem()) return QColor(Qt::black);
	if (type == NodeTypes::morison()) return QColor(Qt::yellow);
	if (type == NodeTypes::pile()) return QColor(Qt::green);
	if (type == NodeTypes::sediment()) return QColor(Qt::magenta);
	if (type == NodeTypes::sedimentTransport()) return QColor(Qt::yellow);
	if (type == NodeTypes::water()) return QColor(Qt::blue);
	if (type == NodeTypes::wave()) return QColor(Qt::cyan);
	if (type == NodeTypes::waveDynamic()) return QColor(Qt::yellow);

	return QVariant();
}
