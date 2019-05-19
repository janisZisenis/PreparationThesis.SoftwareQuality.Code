#include "SolutionExplorerPresenter.h"
#include "SolutionExplorer.h"
#include <model/HierarchyNode/HierarchyNode.h>
#include <item/HierarchicItem/TreeItem/TreeItem.h>
#include <model/Commands/EditCommand.h>
#include <model/Editor/Editor.h>
#include <model/HierarchyNode/HierarchyNodeProperties.h>
#include <utilities/CommandQueue/AddCommandService.h>

SolutionExplorerPresenterPtr SolutionExplorerPresenter::getNewInstance(SolutionExplorer *view, AddCommandServicePtr commandService) {
    return SolutionExplorerPresenterPtr(new SolutionExplorerPresenter(view, commandService));
}

SolutionExplorerPresenter::~SolutionExplorerPresenter() {}

SolutionExplorerPresenter::SolutionExplorerPresenter(SolutionExplorer *view, AddCommandServicePtr commandService) : view(view), commandService(commandService) {}

void SolutionExplorerPresenter::onVisibilityChanged() {
    notify();
}

void SolutionExplorerPresenter::onSelectionChanged() {
    TreeItem* selectedItem = view->getSelectedItem();
    this->selectedNode = selectedItem->getNode();

    notify();
}

HierarchyNodePtr SolutionExplorerPresenter::getSelectedNode() {
    return this->selectedNode;
}

void SolutionExplorerPresenter::onItemEdited(std::string newName) {
    if(!selectedNode) return;
    commandService->add(makeEditNameCommand(selectedNode->makeEditor(), newName));
}

CommandPtr SolutionExplorerPresenter::makeEditNameCommand(EditorPtr editor, std::string name) {
    return EditCommand::getNewInstance(editor, HierarchyNodeProperties::name(), name);
}
