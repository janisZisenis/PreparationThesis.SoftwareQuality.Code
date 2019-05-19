#pragma once

#include <memory>
#include <qtView/MyQItemModel/MyQItemModel.h>
#include <qtView/qtView_Export.h>

class TableItem;
class HierarchicItem;

class qtView_EXPORT MyQItemTableModel : public MyQItemModel {
public:
    Q_OBJECT
public:
    MyQItemTableModel(std::shared_ptr<TableItem> root);
    virtual ~MyQItemTableModel();
signals:
    void propertyEdited(std::string propertyName, std::string propertyValue);
public:
    Qt::ItemFlags flags(const QModelIndex &index) const Q_DECL_OVERRIDE;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) Q_DECL_OVERRIDE;

protected:    
	virtual QVariant getDataAt(HierarchicItem* item, int role, int col) const override;

    std::shared_ptr<TableItem> root;
};
