#ifndef MODEL_ADDNODECOMMAND_H
#define MODEL_ADDNODECOMMAND_H

#include <model/model_Export.h>
#include <utilities/Object/Object.h>
#include <utilities/CommandQueue/Command.h>

class HierarchyNode;
class AddRemoveNodeService;

class AddNodeCommand;
typedef std::shared_ptr<AddNodeCommand> AddNodeCommandPtr;

class model_EXPORT AddNodeCommand : public Command, public Object {
public:
	static AddNodeCommandPtr getNewInstance(std::shared_ptr<HierarchyNode> node,
												std::shared_ptr<AddRemoveNodeService> addRemoveNodeService);
	virtual ~AddNodeCommand();
private:
	AddNodeCommand(std::shared_ptr<HierarchyNode> node,
					   std::shared_ptr<AddRemoveNodeService> addRemoveNodeService);

public:
	virtual void execute() override;
	virtual void undo() override;
	virtual void redo() override;

private:
	std::shared_ptr<AddRemoveNodeService> addRemoveNodeService;
	std::shared_ptr<HierarchyNode> node;
};

#endif //MODEL_ADDNODECOMMAND_H