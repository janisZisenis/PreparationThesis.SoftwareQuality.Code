#ifndef MODEL_VISITORCOMMAND_H
#define MODEL_VISITORCOMMAND_H

#include <model/model_Export.h>
#include <utilities/Object/Object.h>
#include <utilities/CommandQueue/Command.h>

class Visitable;
class Visitor;

class VisitorCommand;
typedef std::shared_ptr<VisitorCommand> VisitorCommandPtr;

class model_EXPORT VisitorCommand : public Command, public Object {
public:
	static VisitorCommandPtr getNewInstance(std::shared_ptr<Visitable> visitable, std::shared_ptr<Visitor> visitor);
	virtual ~VisitorCommand();
private:
	VisitorCommand(std::shared_ptr<Visitable> parent, std::shared_ptr<Visitor> visitor);

public:
	virtual void execute() override;
	virtual void undo() override;
	virtual void redo() override;

	std::shared_ptr<Visitor> visitor;
    std::shared_ptr<Visitable> visitable;
};

#endif //MODEL_VISITORCOMMAND_H