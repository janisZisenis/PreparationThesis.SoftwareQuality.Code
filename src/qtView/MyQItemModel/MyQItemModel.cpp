#include "MyQItemModel.h"
#include <item/HierarchicItem/HierarchicItem.h>

MyQItemModel::MyQItemModel(HierarchicItemPtr root) : QAbstractItemModel(), root(root) {}
MyQItemModel::~MyQItemModel() {}

QModelIndex MyQItemModel::parent(const QModelIndex &child) const {
	HierarchicItem* parentItem = getParentItem(getItem(child));
	if (!parentItem || parentItem == root.get()) return QModelIndex();
	return createIndex(parentItem->getRow(), 0, parentItem);
}

int MyQItemModel::rowCount(const QModelIndex &parent) const {
	return getItem(parent)->getChildCount();
}

int MyQItemModel::columnCount(const QModelIndex &parent) const {
    return 2;
}

QVariant MyQItemModel::data(const QModelIndex &index, int role) const {
	return getDataAt(getItem(index), role, index.column());
}

QModelIndex MyQItemModel::index(int row, int column, const QModelIndex &parent) const {
	HierarchicItem *childItem = getChildItem(getItem(parent), row);
	if (!childItem) return QModelIndex();
	return createIndex(row, column, childItem);
}

HierarchicItem* MyQItemModel::getCurrentItem(const QModelIndex &currentIndex) {
	return getItem(currentIndex);
}

HierarchicItem *MyQItemModel::getItem(const QModelIndex &index) const {
	if (!index.isValid()) return root.get();
	return static_cast<HierarchicItem*>(index.internalPointer());
}

HierarchicItem* MyQItemModel::getChildItem(HierarchicItem* parent, int row) const {
	if (row < parent->getChildCount())
		return parent->getChildAt(row).get();
	return nullptr;
}

HierarchicItem* MyQItemModel::getParentItem(HierarchicItem* child) const {
	if (!child->getParent()) return nullptr;
	return child->getParent().get();
}

QModelIndex MyQItemModel::getIndex(HierarchicItemPtr item) {
	if (item == root) return QModelIndex();
	return createIndex(item->getRow(), 0, item.get());
}