#ifndef QTVIEW_MYQVIEWMENU_H
#define QTVIEW_MYQVIEWMENU_H

#include <qtView/qtView_Export.h>
#include <QMenu>
#include "presenter/MenuPresenter/ViewMenuPresenter/ViewMenu.h"

class ViewMenuPresenter;

class qtView_EXPORT MyQViewMenu : public QMenu, public ViewMenu
{
public:
	Q_OBJECT
public:
	MyQViewMenu();
	virtual ~MyQViewMenu();

public:
	virtual void clearEntries() override;
	virtual void addCheckedEntry(std::string entry) override;
	virtual void addUncheckedEntry(std::string entry) override;

	virtual void setPresenter(std::shared_ptr<ViewMenuPresenter> presenter);
private:
	virtual QAction* createCheckableAction(std::string entry);
	virtual void initializeComponent();

private slots:
	virtual void entryClicked(QAction* action);

private:
	std::shared_ptr<ViewMenuPresenter> presenter;
};


#endif //QTVIEW_MYQVIEWMENU_H