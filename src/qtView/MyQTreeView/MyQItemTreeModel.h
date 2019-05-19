#ifndef QTVIEW_MYQITEMTREEMODEL_H
#define QTVIEW_MYQITEMTREEMODEL_H

#include <qtView/qtView_Export.h>
#include <qtView/MyQItemModel/MyQItemModel.h>
#include <QVariant>

class TreeItem;

class qtView_EXPORT MyQItemTreeModel : public MyQItemModel {
public:
    Q_OBJECT
public:
    MyQItemTreeModel(std::shared_ptr<TreeItem> root);
    virtual ~MyQItemTreeModel();
signals:
    void itemEdited(std::string newName);

public: //slots
    void onBeginInsertItem(std::shared_ptr<HierarchicItem> parent, int index);
    void onEndInsertItem();
    void onBeginRemoveItem(std::shared_ptr<HierarchicItem> parent, int index);
    void onEndRemoveItem();
    void onBeginReplaceItem(std::shared_ptr<HierarchicItem> parent, int index);
    void onEndReplaceItem();
    void onItemDataChanged(std::shared_ptr<HierarchicItem> item);
public:
    virtual QVariant headerData(int section, Qt::Orientation orientation, int role) const Q_DECL_OVERRIDE;
    virtual Qt::ItemFlags flags(const QModelIndex &index) const Q_DECL_OVERRIDE;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) Q_DECL_OVERRIDE;
protected:
    virtual QVariant getDataAt(HierarchicItem* item, int role, int col) const override;
private:
	QVariant getIcon(std::string type) const;
    void connectTo(std::shared_ptr<TreeItem> myRoot);
    void disconnectFrom(std::shared_ptr<TreeItem> myRoot);
};

#endif //QTVIEW_MYQITEMTREEMODEL_H