#include "MyQSolutionExplorer.h"
#include <presenter/DockViewPresenter/SolutionExplorerPresenter/SolutionExplorerPresenter.h>
#include <item/HierarchicItem/TreeItem/TreeItem.h>
#include "qtView/MyQTreeView/MyQTreeView.h"
#include "qtView/MyQTreeView/MyQItemTreeModel.h"

MyQSolutionExplorer::MyQSolutionExplorer(MyQTreeView* treeView, MyQItemTreeModel* model)
        : MyQDockWidget("Solution Explorer"), treeView(treeView), model(model){
    treeView->setMyQItemTreeModel(model);
    initializeComponent();
}
MyQSolutionExplorer::~MyQSolutionExplorer(){}

std::string MyQSolutionExplorer::getTitle() {
    return MyQDockWidget::getTitle();
}

bool MyQSolutionExplorer::isVisible() {
    return MyQDockWidget::isVisible();
}

void MyQSolutionExplorer::changeVisibility() {
    MyQDockWidget::changeVisibility();
}

TreeItem* MyQSolutionExplorer::getSelectedItem() {
    return dynamic_cast<TreeItem*>(model->getCurrentItem(treeView->getCurrentIndex()));
}

void MyQSolutionExplorer::setPresenter(SolutionExplorerPresenterPtr presenter) {
    this->presenter = presenter;
}

void MyQSolutionExplorer::initializeComponent(){
    connect(treeView->selectionModel(), SIGNAL(selectionChanged(const QItemSelection, const QItemSelection)),
            this, SLOT(onSelectionChanged(const QItemSelection, const QItemSelection)));
    connect(this, SIGNAL(visibilityChanged(bool)), this,SLOT(onVisibilityChanged(bool)));
    connect(model, SIGNAL(itemEdited(std::string)), this,SLOT(onItemEdited(std::string)));

    this->setWidget(treeView);
}

void MyQSolutionExplorer::onVisibilityChanged(bool visible) {
    this->presenter->onVisibilityChanged();
}

void MyQSolutionExplorer::onSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected) {
    presenter->onSelectionChanged();
}

void MyQSolutionExplorer::onItemEdited(std::string newName) {
    this->presenter->onItemEdited(newName);
}

