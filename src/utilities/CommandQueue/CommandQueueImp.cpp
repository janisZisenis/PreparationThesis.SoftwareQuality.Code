#include "CommandQueueImp.h"
#include "Command.h"

CommandQueueImpPtr CommandQueueImp::getNewInstance() {
    return CommandQueueImpPtr(new CommandQueueImp());
}

CommandQueueImp::~CommandQueueImp() {}

CommandQueueImp::CommandQueueImp() {}

void CommandQueueImp::add(CommandPtr command) {
    removeCommandsAfterCurrent();

    if (false == throwsExceptionWhenExecuting(command))
        addCommandToQueue(command);

    notify();
}

void CommandQueueImp::undo() {
    if (!undoIsPossible()) throw new CommandsOutOfBoundsException();
    else commands[currentPos--]->undo();

    notify();
}

void CommandQueueImp::redo() {
    if (!redoIsPossible()) throw new CommandsOutOfBoundsException();
    else commands[++currentPos]->redo();

    notify();
}

bool CommandQueueImp::undoIsPossible() {
    if (currentPos > -1) return true;

    return false;
}

bool CommandQueueImp::redoIsPossible() {
    if (currentPos < (int) commands.size() - 1) return true;

    return false;
}

bool CommandQueueImp::throwsExceptionWhenExecuting(CommandPtr command) {
    try {
        command->execute();
        return false;
    }
    catch (CommandException *e) {
        delete e;
        return true;
    }
}

void CommandQueueImp::addCommandToQueue(CommandPtr command) {
    commands.push_back(command);

    currentPos++;
}

void CommandQueueImp::removeCommandsAfterCurrent() {
    while (redoIsPossible())
        commands.pop_back();
}