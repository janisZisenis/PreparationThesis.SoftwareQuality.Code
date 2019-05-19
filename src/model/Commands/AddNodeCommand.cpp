#include "AddNodeCommand.h"

#include "model/HierarchyNode/ProjectHierarchy/AddRemoveNodeService.h"
#include "model/HierarchyNode/HierarchyNode.h"


AddNodeCommandPtr AddNodeCommand::getNewInstance(HierarchyNodePtr node, AddRemoveNodeServicePtr addRemoveNodeService) {
	return AddNodeCommandPtr(new AddNodeCommand(node, addRemoveNodeService));
}
AddNodeCommand::~AddNodeCommand() {}
AddNodeCommand::AddNodeCommand(HierarchyNodePtr node, AddRemoveNodeServicePtr addRemoveNodeService)
		: node(node), addRemoveNodeService(addRemoveNodeService) {}

void AddNodeCommand::execute() {
    try{
        addRemoveNodeService->addChild(node);
    }
    catch (std::exception *e) {
        throw new CommandException();
    }
}

void AddNodeCommand::undo() {
	addRemoveNodeService->removeChild(node);
}

void AddNodeCommand::redo() {
	execute();
}
