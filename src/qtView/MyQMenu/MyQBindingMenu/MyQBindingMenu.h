#ifndef QTVIEW_MYQBINDINGMENU_H
#define QTVIEW_MYQBINDINGMENU_H

#include <memory>
#include <qtView/qtView_Export.h>
#include <QMenu>
#include "presenter/MenuPresenter/BindingMenuPresenter/BindingMenu.h"

class BindingMenuPresenter;

class qtView_EXPORT MyQBindingMenu : public QMenu, public BindingMenu {
public:
	Q_OBJECT
public:
    MyQBindingMenu();
	virtual ~MyQBindingMenu();

	virtual void clearEntries() override;
	virtual void addEntry(std::string entry) override;
	virtual void disableMenu() override;
	virtual void enableMenu() override;
	virtual bool containsEntries() override;

	virtual void setPresenter(std::shared_ptr<BindingMenuPresenter> presenter);
private:
    void initializeComponent();

private slots:
	virtual void entryClicked(QAction *action);

private:
	std::shared_ptr<BindingMenuPresenter> presenter;
};


#endif //QTVIEW_MYQBINDINGMENU_H