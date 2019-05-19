#ifndef UTILITIES_COMMANDQUEUEIMP_H
#define UTILITIES_COMMANDQUEUEIMP_H

#include <utilities/utilities_Export.h>
#include <utilities/Observer/Subject.h>
#include <deque>
#include "CommandQueue.h"
#include "AddCommandService.h"

class Command;

class CommandQueueImp;
typedef std::shared_ptr<CommandQueueImp> CommandQueueImpPtr;

class utilities_EXPORT CommandQueueImp : public CommandQueue, public AddCommandService, public Subject {
public:
	static CommandQueueImpPtr getNewInstance();
	virtual ~CommandQueueImp();
protected:
	CommandQueueImp();

public:
	virtual void add(std::shared_ptr<Command> command) override;
	virtual void undo() override;
	virtual void redo() override;

	virtual bool undoIsPossible() override;
	virtual bool redoIsPossible() override;
private:
	virtual bool throwsExceptionWhenExecuting(std::shared_ptr<Command> command);
	virtual void addCommandToQueue(std::shared_ptr<Command> command);
	virtual void removeCommandsAfterCurrent();

	std::deque<std::shared_ptr<Command> > commands;
	int currentPos = -1;
};



#endif //UTILITIES_COMMANDQUEUEIMP_H