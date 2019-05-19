#include "AddNodeMenuPresenter.h"

#include <model/HierarchyNodeFactory/HierarchyNodeFactory.h>
#include <model/HierarchyNode/ProjectHierarchy/AddRemoveNodeService.h>
#include <utilities/CommandQueue/AddCommandService.h>
#include <model/Commands/AddNodeCommand.h>
#include <model/HierarchyNode/HierarchyNode.h>
#include "AddNodeMenu.h"

AddNodeMenuPresenterPtr AddNodeMenuPresenter::getNewInstance(AddNodeMenu *addNodeMenu, AddCommandServicePtr commandService,
                                                             AddRemoveNodeServicePtr nodeService, HierarchyNodeFactoryPtr nodeFactory) {
    return AddNodeMenuPresenterPtr(new AddNodeMenuPresenter(addNodeMenu, commandService, nodeService, nodeFactory));
}
AddNodeMenuPresenter::~AddNodeMenuPresenter() {}
AddNodeMenuPresenter::AddNodeMenuPresenter(AddNodeMenu *addNodeMenu, AddCommandServicePtr commandService,
                                           AddRemoveNodeServicePtr nodeService, HierarchyNodeFactoryPtr nodeFactory)
        : addNodeMenu(addNodeMenu), commandService(commandService), nodeService(nodeService),
          nodeFactory(nodeFactory) {
    addEntriesToMenu();
}

CommandPtr AddNodeMenuPresenter::makeAddNodeCommand(HierarchyNodePtr node) {
    return AddNodeCommand::getNewInstance(node, nodeService);
}

void AddNodeMenuPresenter::addEntriesToMenu() {
    std::vector<std::string> types = nodeFactory->getNodeTypes();

    for(std::string type : types)
        addNodeMenu->addEntry(type);
}

void AddNodeMenuPresenter::onEntryClicked(std::string entry) {
    commandService->add(makeAddNodeCommand(nodeFactory->makeHierarchyNode(entry)));
}