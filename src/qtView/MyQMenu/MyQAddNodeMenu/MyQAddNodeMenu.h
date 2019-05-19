#ifndef QTVIEW_MYQADDNODEMENU_H
#define QTVIEW_MYQADDNODEMENU_H

#include <qtView/qtView_Export.h>
#include <QMenu>
#include "presenter/MenuPresenter/AddNodeMenuPresenter/AddNodeMenu.h"

class AddNodeMenuPresenter;

class qtView_EXPORT MyQAddNodeMenu : public QMenu, public AddNodeMenu {
public:
	Q_OBJECT
public:
	MyQAddNodeMenu();
	virtual ~MyQAddNodeMenu();

	virtual void addEntry(std::string entry) override;

	virtual void setPresenter(std::shared_ptr<AddNodeMenuPresenter> presenter);
private:
	void initializeComponent();
private slots:
	virtual void entryClicked(QAction* action);

private:
	std::shared_ptr<AddNodeMenuPresenter> presenter;
};


#endif //QTVIEW_MYQADDNODEMENU_H