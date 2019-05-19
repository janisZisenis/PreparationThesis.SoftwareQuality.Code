#ifndef MYQSOLUTIONEXPLORER_H
#define MYQSOLUTIONEXPLORER_H

#include <memory>
#include <string>
#include <QItemSelection>
#include "qtView/MyQDockWidget/MyQDockWidget.h"
#include "presenter/DockViewPresenter/SolutionExplorerPresenter/SolutionExplorer.h"

class MyQTreeView;
class MyQItemTreeModel;

class SolutionExplorerPresenter;

class qtView_EXPORT MyQSolutionExplorer : public MyQDockWidget, public SolutionExplorer {
public:
    Q_OBJECT
public:
    MyQSolutionExplorer(MyQTreeView* treeView, MyQItemTreeModel* model);
    virtual ~MyQSolutionExplorer();

    virtual std::string getTitle() override;
    virtual bool isVisible() override;
    virtual void changeVisibility() override;
    virtual TreeItem* getSelectedItem() override;

    virtual void setPresenter(std::shared_ptr<SolutionExplorerPresenter> presenter);
private:
    void initializeComponent();

private slots:
    void onVisibilityChanged(bool visible);
    virtual void onSelectionChanged(const QItemSelection  &selected, const QItemSelection  &deselected);
    virtual void onItemEdited(std::string newName);
private:
    std::shared_ptr<SolutionExplorerPresenter> presenter;
    MyQTreeView* treeView;
    MyQItemTreeModel* model;
};

#endif //MYQSOLUTIONEXPLORER_H