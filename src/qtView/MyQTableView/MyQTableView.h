#ifndef QTVIEW_MYQTABLEVIEW_H
#define QTVIEW_MYQTABLEVIEW_H

#include <qtView/qtView_Export.h>
#include <QTableView>

class MyQItemTableModel;

class qtView_EXPORT MyQTableView : public QTableView
{
public:
	Q_OBJECT
public:
    MyQTableView();
	virtual ~MyQTableView();

    virtual void setMyQItemTableModel(MyQItemTableModel* model);
private:
	void initializeComponent();

    MyQItemTableModel* model = nullptr;
};

#endif //QTVIEW_MYQTABLEVIEW_H