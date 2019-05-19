#ifndef QTVIEW_MYQDOCKWIDGET_H
#define QTVIEW_MYQDOCKWIDGET_H

#include <qtView/qtView_Export.h>
#include <QDockWidget>
#include <string>

class qtView_EXPORT MyQDockWidget : public QDockWidget
{
protected:
	MyQDockWidget(std::string title);
public:
	virtual ~MyQDockWidget();

public:
	virtual void changeVisibility();
	virtual bool isVisible();
	virtual std::string getTitle();
};

#endif //QTVIEW_MYQDOCKWIDGET_H