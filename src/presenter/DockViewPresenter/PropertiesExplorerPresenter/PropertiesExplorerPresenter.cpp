#include "PropertiesExplorerPresenter.h"
#include <presenter/DockViewPresenter/SolutionExplorerPresenter/SelectedNodeAccess.h>
#include <presenter/RootBuilderFactory/RootBuilderFactory.h>
#include <presenter/RootBuilder/RootBuilder.h>
#include <model/HierarchyNode/HierarchyNode.h>
#include "PropertiesExplorer.h"
#include <model/Commands/EditCommand.h>
#include <model/Editor/Editor.h>
#include <utilities/CommandQueue/AddCommandService.h>

PropertiesExplorerPresenterPtr PropertiesExplorerPresenter::getNewInstance(PropertiesExplorer *view,
                                                                           SelectedNodeAccessPtr selectedNodeAccess,
                                                                           RootBuilderFactoryPtr rootBuilderFactory,
                                                                           AddCommandServicePtr commandService) {
    return PropertiesExplorerPresenterPtr(new PropertiesExplorerPresenter(view,
                                                                          selectedNodeAccess,
                                                                          rootBuilderFactory,
                                                                          commandService));
}
PropertiesExplorerPresenter::~PropertiesExplorerPresenter() {}
PropertiesExplorerPresenter::PropertiesExplorerPresenter(PropertiesExplorer *view,
                                                         SelectedNodeAccessPtr selectedNodeAccess,
                                                         RootBuilderFactoryPtr rootBuilderFactory,
                                                         AddCommandServicePtr commandService)
        : view(view),
          selectedNodeAccess(selectedNodeAccess),
          rootBuilderFactory(rootBuilderFactory),
          commandService(commandService){}

void PropertiesExplorerPresenter::update() {
    connectToNewNode(selectedNodeAccess->getSelectedNode());
    RootBuilderPtr rootBuilder = rootBuilderFactory->makeRootBuilder(selectedNode.lock());

    view->setTableRoot(rootBuilder->buildRoot());
}

void PropertiesExplorerPresenter::onVisibilityChanged() {
    notify();
}

void PropertiesExplorerPresenter::onPropertyChanged(std::string propertyName, std::string propertyValue) {
    if(!selectedNode.lock()) return;
    commandService->add(makeEditCommand(selectedNode.lock()->makeEditor(),propertyName, propertyValue));
}

CommandPtr PropertiesExplorerPresenter::makeEditCommand(EditorPtr editor,
                                                          std::string propertyName,
                                                          std::string propertyValue) {
    return EditCommand::getNewInstance(editor, propertyName, propertyValue);
}

void PropertiesExplorerPresenter::connectToNewNode(HierarchyNodePtr newNode) {
    disconnectFromNode();
    connectToNode(newNode);
}
void PropertiesExplorerPresenter::disconnectFromNode() {
    if(!selectedNode.lock()) return;
    selectedNode.lock()->nodeChanged.disconnect(boost::bind(&PropertiesExplorerPresenter::update, this));
	selectedNode.lock()->childInserted.disconnect(boost::bind(&PropertiesExplorerPresenter::update, this));
	selectedNode.lock()->childRemoved.disconnect(boost::bind(&PropertiesExplorerPresenter::update, this));
	selectedNode.lock()->childReplaced.disconnect(boost::bind(&PropertiesExplorerPresenter::update, this));

	selectedNode.reset();
}
void PropertiesExplorerPresenter::connectToNode(HierarchyNodePtr node) {
    selectedNode = node;

    if(!node) return;
    node->nodeChanged.connect(boost::bind(&PropertiesExplorerPresenter::update, this));
	node->childInserted.connect(boost::bind(&PropertiesExplorerPresenter::update, this));
	node->childRemoved.connect(boost::bind(&PropertiesExplorerPresenter::update, this));
	node->childReplaced.connect(boost::bind(&PropertiesExplorerPresenter::update, this));
}

