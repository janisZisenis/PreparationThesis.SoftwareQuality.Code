#include "MyQPropertiesExplorer.h"
#include <presenter/DockViewPresenter/PropertiesExplorerPresenter/PropertiesExplorerPresenter.h>
#include <qtView/MyQTableView/MyQTableView.h>
#include <qtView/MyQTableView/MyQItemTableModel.h>
#include <item/HierarchicItem/TableItem/TableItem.h>

MyQPropertiesExplorer::MyQPropertiesExplorer(MyQTableView* tableView)
        : MyQDockWidget("Properties Explorer"), tableView(tableView) {
    this->initializeComponent();
}
MyQPropertiesExplorer::~MyQPropertiesExplorer() {}

std::string MyQPropertiesExplorer::getTitle() {
    return MyQDockWidget::getTitle();
}

bool MyQPropertiesExplorer::isVisible() {
    return MyQDockWidget::isVisible();
}

void MyQPropertiesExplorer::changeVisibility() {
    MyQDockWidget::changeVisibility();
}

void MyQPropertiesExplorer::setTableRoot(TableItemPtr tableRoot) {
	tableView->reset();
    MyQItemTableModel* model = new MyQItemTableModel(tableRoot);
    connect(model, SIGNAL(propertyEdited(std::string, std::string)), this,SLOT(onPropertyEdited(std::string, std::string)));
    tableView->setMyQItemTableModel(model);
}

void MyQPropertiesExplorer::setPresenter(PropertiesExplorerPresenterPtr presenter) {
    this->presenter = presenter;
}

void MyQPropertiesExplorer::initializeComponent() {
    connect(this, SIGNAL(visibilityChanged(bool)), this,SLOT(onVisibilityChanged(bool)));

    this->setWidget(tableView);
}

void MyQPropertiesExplorer::onVisibilityChanged(bool visible) {
    this->presenter->onVisibilityChanged();
}

void MyQPropertiesExplorer::onPropertyEdited(std::string propertyName, std::string propertyValue) {
    presenter->onPropertyChanged(propertyName, propertyValue);
}

MyQItemTableModel *MyQPropertiesExplorer::makeTableModel(TableItemPtr tableRoot) {
    return new MyQItemTableModel(tableRoot);
}


