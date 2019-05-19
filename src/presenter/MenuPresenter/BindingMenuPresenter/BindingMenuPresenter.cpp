#include "BindingMenuPresenter.h"
#include <utilities/CommandQueue/AddCommandService.h>
#include "BindingMenu.h"
#include <model/HierarchyNode/HierarchyNode.h>
#include <model/HierarchyNode/ProjectHierarchy/ProjectHierarchyService.h>
#include <presenter/DockViewPresenter/SolutionExplorerPresenter/SelectedNodeAccess.h>
#include <model/Commands/VisitorCommand.h>
#include <utilities/Visitor/Visitor.h>

BindingMenuPresenterPtr BindingMenuPresenter::getNewInstance(BindingMenu *bindingMenu,
                                                             AddCommandServicePtr commandService,
                                                             ProjectHierarchyServicePtr projectHierarchyService,
                                                             SelectedNodeAccessPtr selectedNodeAccess) {
    return BindingMenuPresenterPtr(new BindingMenuPresenter(bindingMenu, commandService,
                                                            projectHierarchyService, selectedNodeAccess));
}

BindingMenuPresenter::~BindingMenuPresenter() {}

BindingMenuPresenter::BindingMenuPresenter(BindingMenu *bindingMenu,
                                           AddCommandServicePtr commandService,
                                           ProjectHierarchyServicePtr projectHierarchyService,
                                           SelectedNodeAccessPtr selectedNodeAccess)
        : bindingMenu(bindingMenu), commandService(commandService),
          projectHierarchyService(projectHierarchyService),
          selectedNodeAccess(selectedNodeAccess) {
    update();
}

void BindingMenuPresenter::onEntryClicked(std::string entry) {
    std::vector<HierarchyNodePtr> nodes = projectHierarchyService->getNodes();
    HierarchyNodePtr parent = nullptr;

    for(HierarchyNodePtr node : nodes)
        if(node->getName() == entry){
            parent = node;
            break;
        }

    if(parent) commandService->add(makeBindingCommand(parent, selectedNodeAccess->getSelectedNode()->makeBinder()));
}

void BindingMenuPresenter::update() {
    std::vector<HierarchyNodePtr> nodes = projectHierarchyService->getNodes();
    HierarchyNodePtr selected = selectedNodeAccess->getSelectedNode();

    bindingMenu->clearEntries();
    bindingMenu->disableMenu();

    for(HierarchyNodePtr node : nodes)
        if (node->canBind(selected))
            bindingMenu->addEntry(node->getName());

    if(bindingMenu->containsEntries())
        bindingMenu->enableMenu();
}

CommandPtr BindingMenuPresenter::makeBindingCommand(VisitablePtr visitable, VisitorPtr binder) {
    return VisitorCommand::getNewInstance(visitable, binder);
}

