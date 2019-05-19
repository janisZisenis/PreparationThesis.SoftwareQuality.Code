#ifndef QTVIEW_MYQPROPERTIESEXPLORER_H
#define QTVIEW_MYQPROPERTIESEXPLORER_H

#include <memory>
#include <string>
#include "qtView/MyQDockWidget/MyQDockWidget.h"
#include "presenter/DockViewPresenter/PropertiesExplorerPresenter/PropertiesExplorer.h"

class MyQTableView;
class MyQItemTableModel;

class PropertiesExplorerPresenter;
class qtView_EXPORT MyQPropertiesExplorer : public MyQDockWidget, public PropertiesExplorer {
public:
	Q_OBJECT
public:
	MyQPropertiesExplorer(MyQTableView* tableView);
	virtual ~MyQPropertiesExplorer();

	virtual std::string getTitle() override;
	virtual bool isVisible() override;
	virtual void changeVisibility() override;

	virtual void setTableRoot(std::shared_ptr<TableItem> tableRoot) override;
    virtual void setPresenter(std::shared_ptr<PropertiesExplorerPresenter> presenter);
private:
	void initializeComponent();

private slots:
	virtual void onVisibilityChanged(bool visible);
	virtual void onPropertyEdited(std::string propertyName, std::string propertyValue);
private:
	MyQItemTableModel* makeTableModel(std::shared_ptr<TableItem> tableRoot);
    std::shared_ptr<PropertiesExplorerPresenter> presenter;
	MyQTableView* tableView;
};

#endif //QTVIEW_MYQPROPERTIESEXPLORER_H