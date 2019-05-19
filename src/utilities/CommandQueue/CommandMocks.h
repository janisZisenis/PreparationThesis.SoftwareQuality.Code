#ifndef UTILITIES_COMMANDMOCKS_H
#define UTILITIES_COMMANDMOCKS_H

#include "Command.h"

class CommandExceptionDummy : public CommandException {
public:
    const char *what() const throw() {
        std::ostringstream getNr;
        getNr << "Hey There, i am a dummy CommandException!";
        return getNr.str().c_str();
    }
};

enum CommandState {
    Empty, Executed, Undone, Redone
};

class CommandDummy;
typedef std::shared_ptr<CommandDummy> CommandDummyPtr;
class CommandDummy : public Command {
public:
    static CommandDummyPtr getNewInstance() {
        return CommandDummyPtr(new CommandDummy());
    }

    virtual ~CommandDummy() {}

protected:
    CommandDummy() {}

public:
    virtual void execute() override {}
    virtual void undo() override {}
    virtual void redo() override {}
};

class ThrowingCommandStub;
typedef std::shared_ptr <ThrowingCommandStub> ThrowingCommandStubPtr;
class ThrowingCommandStub : public CommandDummy {
public:
    static ThrowingCommandStubPtr getNewInstance() {
        return ThrowingCommandStubPtr(new ThrowingCommandStub());
    }

    virtual ~ThrowingCommandStub() {}
protected:
    ThrowingCommandStub() {}

public:
    virtual void execute() override {
        throwCommandException();
    };
    virtual void undo() override {
        throwCommandException();
    };
    virtual void redo() override {
        throwCommandException();
    };
private:
    virtual void throwCommandException() {
        throw new CommandExceptionDummy();
    }
};

class CommandStateSpy;
typedef std::shared_ptr <CommandStateSpy> CommandStateSpyPtr;
class CommandStateSpy : public CommandDummy {
public:
    static CommandStateSpyPtr getNewInstance() {
        return CommandStateSpyPtr(new CommandStateSpy());
    }
    virtual ~CommandStateSpy() {}

protected:
    CommandStateSpy() {
        commandState = CommandState::Empty;
    }

public:
    virtual void execute() override {
        this->commandState = CommandState::Executed;
    };
    virtual void undo() override {
        this->commandState = CommandState::Undone;
    };
    virtual void redo() override {
        this->commandState = CommandState::Redone;
    };

    int getCommandState() {
        return this->commandState;
    }

private:
    int commandState;
};

#endif //UTILITIES_COMMANDMOCKS_H