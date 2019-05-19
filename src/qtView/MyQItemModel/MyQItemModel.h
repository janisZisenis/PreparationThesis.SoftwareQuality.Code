#ifndef QTVIEW_MYQITEMMODEL_H
#define QTVIEW_MYQITEMMODEL_H

#include <qtView/qtView_Export.h>
#include <QAbstractItemModel>
#include <memory>

class HierarchicItem;

class qtView_EXPORT MyQItemModel : public QAbstractItemModel {
public:
    MyQItemModel(std::shared_ptr<HierarchicItem> root);
    virtual ~MyQItemModel();
public:
    virtual QModelIndex parent(const QModelIndex &child) const Q_DECL_OVERRIDE;
    virtual int rowCount(const QModelIndex &index) const Q_DECL_OVERRIDE;
    virtual int columnCount(const QModelIndex &index) const Q_DECL_OVERRIDE;
    virtual QVariant data(const QModelIndex &index, int role) const Q_DECL_OVERRIDE;
    virtual QModelIndex index(int row, int column, const QModelIndex &parent) const Q_DECL_OVERRIDE;

	virtual HierarchicItem* getCurrentItem(const QModelIndex &currentIndex);
protected:
    virtual QVariant getDataAt(HierarchicItem* item, int role, int col) const = 0;

	virtual HierarchicItem* getItem(const QModelIndex &index) const;
	HierarchicItem* getChildItem(HierarchicItem* parent, int row) const;
    HierarchicItem* getParentItem(HierarchicItem* child) const;
    QModelIndex getIndex(std::shared_ptr<HierarchicItem> item);

protected:
    std::shared_ptr<HierarchicItem> root;
};

#endif //QTVIEW_MYQITEMMODEL_H