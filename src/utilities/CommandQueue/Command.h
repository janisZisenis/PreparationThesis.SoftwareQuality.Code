#ifndef UTILITIES_COMMAND_H
#define UTILITIES_COMMAND_H

#include <memory>
#include <utilities/utilities_Export.h>

class Command;
typedef std::shared_ptr<Command> CommandPtr;

class Command {
public:
	virtual void execute() = 0;
	virtual void undo() = 0;
	virtual void redo() = 0;
};

class utilities_EXPORT CommandException : public std::exception {
public:
	virtual const char *what() const throw();
};

#endif //UTILITIES_COMMAND_H