#include "MyQItemTableModel.h"
#include "item/HierarchicItem/TableItem/TableItem.h"

MyQItemTableModel::~MyQItemTableModel() {}

MyQItemTableModel::MyQItemTableModel(TableItemPtr root) : MyQItemModel(root) {}

Qt::ItemFlags MyQItemTableModel::flags(const QModelIndex &index) const {
	TableItem* item = dynamic_cast<TableItem*>(getItem(index));
	if (!item || (!item->isEditable() && index.column() == 1))
		return Qt::NoItemFlags;
	if (index.column() == 1)
		return QAbstractItemModel::flags(index) |= Qt::ItemIsEditable;
	return QAbstractItemModel::flags(index);
}

QVariant MyQItemTableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole) {
        if (section == 0) return "Property";
        if (section == 1) return "Value";
    }
    return QVariant();
}

bool MyQItemTableModel::setData(const QModelIndex &index, const QVariant &value, int role) {
	if (role != Qt::EditRole)
		return false;
	
	TableItem *item = dynamic_cast<TableItem*>(getItem(index));
	if (!item) return false;
	
	this->propertyEdited(item->getPropertyName(), value.toString().toStdString());

	return false;
}

QVariant MyQItemTableModel::getDataAt(HierarchicItem* item, int role, int col) const {
	TableItem* tableItem = dynamic_cast<TableItem*>(item);
	if (!tableItem) return QVariant();

	if (role == Qt::DisplayRole) {
		if (col == 0) return QString::fromStdString(tableItem->getFirstColumn());
		if (col == 1) return QString::fromStdString(tableItem->getPropertyValue());
	}

	return QVariant();
}

