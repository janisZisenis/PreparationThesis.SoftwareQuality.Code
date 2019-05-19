#include "VisitorCommand.h"
#include <utilities/Visitor/Visitor.h>
#include <utilities/Visitor/Visitable.h>

VisitorCommandPtr VisitorCommand::getNewInstance(VisitablePtr visitable, VisitorPtr visitor) {
    return VisitorCommandPtr(new VisitorCommand(visitable, visitor));
}

VisitorCommand::~VisitorCommand() {}

VisitorCommand::VisitorCommand(VisitablePtr visitable, VisitorPtr visitor) : visitable(visitable), visitor(visitor) {}

void VisitorCommand::execute() {
    try{
        visitable->accept(visitor);
    }
    catch (std::exception *e) {
        throw new CommandException();
    }
}

void VisitorCommand::undo() {
    visitable->accept(visitor);
}

void VisitorCommand::redo() {
    this->execute();
}
