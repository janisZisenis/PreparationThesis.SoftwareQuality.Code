#include <QApplication>
#include <utilities/Object/LoggingObject.h>
#include <utilities/Logger/ConsoleLogger.h>
#include <qtView/MyQShell/MyQShell.h>

#include <qtView/MyQDockWidget/MyQPropertiesExplorer/MyQPropertiesExplorer.h>
#include <presenter/DockViewPresenter/PropertiesExplorerPresenter/PropertiesExplorerPresenter.h>
#include <qtView/MyQDockWidget/MyQSolutionExplorer/MyQSolutionExplorer.h>
#include <presenter/DockViewPresenter/SolutionExplorerPresenter/SolutionExplorerPresenter.h>
#include <qtView/MyQMenu/MyQViewMenu/MyQViewMenu.h>
#include <presenter/MenuPresenter/ViewMenuPresenter/ViewMenuPresenter.h>
#include <qtView/MyQMenu/MyQAddNodeMenu/MyQAddNodeMenu.h>
#include <presenter/MenuPresenter/AddNodeMenuPresenter/AddNodeMenuPresenter.h>
#include <model/HierarchyNodeFactory/HierarchyNodeFactoryImp.h>
#include <utilities/CommandQueue/CommandQueueImp.h>
#include <model/HierarchyNode/ProjectHierarchy/ProjectHierarchy.h>
#include <qtView/MyQTreeView/MyQItemTreeModel.h>
#include <qtView/MyQTreeView/MyQTreeView.h>
#include <qtView/MyQTableView/MyQTableView.h>
#include <qtView/MyQMenu/MyQEditMenu/MyQEditMenu.h>
#include <presenter/MenuPresenter/EditMenuPresenter/EditMenuPresenter.h>
#include <qtView/MyQMenu/MyQBindingMenu/MyQBindingMenu.h>
#include <presenter/MenuPresenter/BindingMenuPresenter/BindingMenuPresenter.h>
#include <presenter/RootBuilderFactory/RootBuilderFactoryImp.h>
#include <item/TreeItemFactory/TreeItemFactoryImp.h>
#include <item/HierarchicItem/TreeItem/NodeItem/ProjectHierarchyItem/ProjectHierarchyItem.h>
#include <qtView/MyQMenu/MyQEvaluateMenu/MyQEvaluateMenu.h>
#include <presenter/MenuPresenter/EvaluateMenuPresenter/EvaluateMenuPresenter.h>
#include <qtView/MyQViewFactoryImp/MyQViewFactoryImp.h>

#include <model/Commands/AddNodeCommand.h>
#include <model/HierarchyNode/Pile/Pile.h>

int main(int argc, char** argv) {
    QApplication app(argc, argv);
    LoggingObject::addLogger(ConsoleLogger::getNewInstance());

/////////////////////////////////////////////////// MODEL ///////////////////////////////////////////////////
    HierarchyNodeFactoryImpPtr nodeFactory = HierarchyNodeFactoryImp::getNewInstance();
    CommandQueueImpPtr commandQueue = CommandQueueImp::getNewInstance();
    ProjectHierarchyPtr projectHierarchy = ProjectHierarchy::getNewInstance();

/////////////////////////////////////////////////// ITEM ////////////////////////////////////////////////////
    TreeItemFactoryImpPtr itemFactory = TreeItemFactoryImp::getNewInstance();
    TreeItemPtr root = ProjectHierarchyItem::getNewInstance(projectHierarchy, itemFactory);

/////////////////////////////////////////////////// VIEW ////////////////////////////////////////////////////
    MyQShell* shell = new MyQShell();
    shell->setMinimumSize(800, 600);

    MyQTreeView* treeView = new MyQTreeView();
    MyQItemTreeModel* treeModel = new MyQItemTreeModel(root);
    MyQSolutionExplorer *solView = new MyQSolutionExplorer(treeView, treeModel);

	MyQTableView* tableView = new MyQTableView();
    MyQPropertiesExplorer *propView = new MyQPropertiesExplorer(tableView);

    MyQViewMenu *viewMenu = new MyQViewMenu();
    MyQAddNodeMenu* addNodeMenu = new MyQAddNodeMenu();
    MyQEditMenu *editMenu = new MyQEditMenu();
    MyQBindingMenu* bindingMenu = new MyQBindingMenu();
    MyQEvaluateMenu* evaluateMenu = new MyQEvaluateMenu();

    QMenu* dataMenu = new QMenu("Data");
    dataMenu->addMenu(addNodeMenu);
    dataMenu->addMenu(bindingMenu);
    dataMenu->addMenu(evaluateMenu);

    shell->addMenu(viewMenu);
    shell->addMenu(editMenu);
    shell->addMenu(dataMenu);

///////////////////////////////////////////////// PRESENTER /////////////////////////////////////////////////
    SolutionExplorerPresenterPtr solPresenter = SolutionExplorerPresenter::getNewInstance(solView, commandQueue);
    solView->setPresenter(solPresenter);

    PropertiesExplorerPresenterPtr propPresenter = PropertiesExplorerPresenter::getNewInstance(
            propView, solPresenter, RootBuilderFactoryImp::getNewInstance(), commandQueue);
    propView->setPresenter(propPresenter);
    solPresenter->attach(propPresenter);

    ViewMenuPresenterPtr viewMenuPresenter = ViewMenuPresenter::getNewInstance(viewMenu, shell);
    viewMenu->setPresenter(viewMenuPresenter);
    viewMenuPresenter->addView(solView);
    viewMenuPresenter->addView(propView);
    propPresenter->attach(viewMenuPresenter);
    solPresenter->attach(viewMenuPresenter);

    AddNodeMenuPresenterPtr addNodeMenuPresenter = AddNodeMenuPresenter::getNewInstance(
            addNodeMenu, commandQueue, projectHierarchy, nodeFactory);
    addNodeMenu->setPresenter(addNodeMenuPresenter);

    EditMenuPresenterPtr editMenuPresenter = EditMenuPresenter::getNewInstance(editMenu, commandQueue);
    editMenu->setPresenter(editMenuPresenter);
    commandQueue->attach(editMenuPresenter);

    EvaluateMenuPresenterPtr evaluateMenuPresenter = EvaluateMenuPresenter::getNewInstance(
            evaluateMenu, shell, solPresenter, MyQViewFactoryImp::getNewInstance());
    evaluateMenu->setPresenter(evaluateMenuPresenter);
    solPresenter->attach(evaluateMenuPresenter);

    BindingMenuPresenterPtr bindingMenuPresenter = BindingMenuPresenter::getNewInstance(
            bindingMenu,commandQueue, projectHierarchy, solPresenter);
    bindingMenu->setPresenter(bindingMenuPresenter);
    solPresenter->attach(bindingMenuPresenter);
    projectHierarchy->attach(bindingMenuPresenter);


	/////////////////////////////////////////////////// SET UP //////////////////////////////////////////////////
	//for (int i = 0; i < 1000; i++)
	//	commandQueue->add(AddNodeCommand::getNewInstance(Pile::getNewInstance(), projectHierarchy));
	//for (int i = 0; i < 1000; i++)
	//	commandQueue->undo();
	//for (int i = 0; i < 1000; i++)
	//	commandQueue->redo();

	///////////////////////////////////////////// START APPLICATION /////////////////////////////////////////////
	shell->show();
	return app.exec();
}
