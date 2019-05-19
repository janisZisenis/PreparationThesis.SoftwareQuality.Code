#include "EvaluateMenuPresenter.h"
#include "EvaluateMenu.h"
#include "ViewFactory.h"
#include <presenter/DockViewPresenter/SolutionExplorerPresenter/SelectedNodeAccess.h>
#include <model/HierarchyNode/HierarchyNode.h>
#include <presenter/Shell/Shell.h>

EvaluateMenuPresenterPtr EvaluateMenuPresenter::getNewInstance(EvaluateMenu *evaluateMenu, Shell* shell, SelectedNodeAccessPtr selectedNodeAccess, ViewFactoryPtr viewFactory) {
    return EvaluateMenuPresenterPtr(new EvaluateMenuPresenter(evaluateMenu, shell, selectedNodeAccess, viewFactory));
}
EvaluateMenuPresenter::~EvaluateMenuPresenter() {}
EvaluateMenuPresenter::EvaluateMenuPresenter(EvaluateMenu *evaluateMenu, Shell* shell, SelectedNodeAccessPtr selectedNodeAccess, ViewFactoryPtr viewFactory)
        : evaluateMenu(evaluateMenu), shell(shell), selectedNodeAccess(selectedNodeAccess), viewFactory(viewFactory) {
    update();
}

void EvaluateMenuPresenter::onEntryClicked(std::string entry) {
    View* view = viewFactory->makeView(entry, selectedNodeAccess->getSelectedNode());
    shell->addEvalutationView(view);
}

void EvaluateMenuPresenter::update() {
    evaluateMenu->clearEntries();
    evaluateMenu->disableMenu();

    HierarchyNodePtr selectedNode = selectedNodeAccess->getSelectedNode();
    if(!selectedNode) return;

    for(std::string entry : viewFactory->getListOfVisualizationsFor(selectedNode->getType()))
        evaluateMenu->addEntry(entry);

    if(evaluateMenu->containsEntries()) evaluateMenu->enableMenu();
}

