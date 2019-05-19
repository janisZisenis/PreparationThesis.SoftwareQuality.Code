#ifndef QTVIEW_MYQEVALUATEMENU_H
#define QTVIEW_MYQEVALUATEMENU_H

#include <memory>
#include <qtView/qtView_Export.h>
#include <QMenu>
#include "presenter/MenuPresenter/EvaluateMenuPresenter/EvaluateMenu.h"

class EvaluateMenuPresenter;

class qtView_EXPORT MyQEvaluateMenu : public QMenu, public EvaluateMenu {
public:
	Q_OBJECT
public:
    MyQEvaluateMenu();
	virtual ~MyQEvaluateMenu();

	virtual void clearEntries() override;
	virtual void addEntry(std::string entry) override;
	virtual void disableMenu() override;
	virtual void enableMenu() override;
	virtual bool containsEntries() override;

	virtual void setPresenter(std::shared_ptr<EvaluateMenuPresenter> presenter);
private:
    void initializeComponent();

private slots:
	virtual void entryClicked(QAction *action);

private:
	std::shared_ptr<EvaluateMenuPresenter> presenter;
};


#endif //QTVIEW_MYQEVALUATEMENU_H