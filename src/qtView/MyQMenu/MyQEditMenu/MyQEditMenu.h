#ifndef QTVIEW_MYQEDITMENU_H
#define QTVIEW_MYQEDITMENU_H

#include <memory>
#include <qtView/qtView_Export.h>
#include <QMenu>
#include "presenter/MenuPresenter/EditMenuPresenter/EditMenu.h"

class EditMenuPresenter;

class qtView_EXPORT MyQEditMenu : public QMenu, public EditMenu {
public:
	Q_OBJECT
public:
    MyQEditMenu();
	virtual ~MyQEditMenu();

	virtual void setPresenter(std::shared_ptr<EditMenuPresenter> presenter);

	virtual void disableUndo() override;
	virtual void enableUndo() override;
	virtual void disableRedo() override;
	virtual void enableRedo() override;

private:
    void initializeComponent();

private slots:
	virtual void undoClicked();
	virtual void redoClicked();

private:
	std::shared_ptr<EditMenuPresenter> presenter;
	QAction* undoAction;
	QAction* redoAction;
};


#endif //QTVIEW_MYQEDITMENU_H