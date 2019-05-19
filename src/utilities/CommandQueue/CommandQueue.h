#ifndef UTILITIES_COMMANDQUEUE_H
#define UTILITIES_COMMANDQUEUE_H

#include <memory>
#include <sstream>

class CommandQueue;
typedef std::shared_ptr<CommandQueue> CommandQueuePtr;

class CommandQueue {
public:
	virtual void undo() = 0;
	virtual void redo() = 0;

	virtual bool undoIsPossible() = 0;
	virtual bool redoIsPossible() = 0;
};

class CommandsOutOfBoundsException : public std::exception {
public:
	virtual const char *what() const throw(){
		std::ostringstream getNr;
		getNr << "Command access out of bounds";
		return getNr.str().c_str();
	};
};

#endif //UTILITIES_COMMANDQUEUE_H