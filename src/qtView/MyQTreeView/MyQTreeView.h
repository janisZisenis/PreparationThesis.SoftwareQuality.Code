#ifndef QTVIEW_MYQTREEVIEW_H
#define QTVIEW_MYQTREEVIEW_H

#include <qtView/qtView_Export.h>
#include <QTreeView>

class TreeItem;
class MyQItemTreeModel;

class qtView_EXPORT MyQTreeView : public QTreeView {
public:
	Q_OBJECT
public:
	MyQTreeView();
	virtual ~MyQTreeView();

    virtual void setMyQItemTreeModel(MyQItemTreeModel* model);
    virtual const QModelIndex getCurrentIndex();

private:
	void initializeComponent();

    MyQItemTreeModel* model;
};

#endif //QTVIEW_MYQTREEVIEW_H