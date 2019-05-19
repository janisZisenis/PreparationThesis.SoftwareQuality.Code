#ifndef UTILITIES_COMMANDQUEUEIMPTEST_H
#define UTILITIES_COMMANDQUEUEIMPTEST_H

#include "gmock/gmock.h"
#include "CommandQueueImp.h"

#include "CommandMocks.h"

class CommandQueueImpTest : public testing::Test {
public:
	void SetUp() override {
		sut = CommandQueueImp::getNewInstance();
	}
	virtual void triggerUndo(int times) {
		for (; times > 0; times--)
			sut->undo();
	}
	virtual void triggerRedo(int times) {
		for (; times > 0; times--)
			sut->redo();
	}
	virtual std::vector<CommandStateSpyPtr>  addCommandStateSpiesToQueue(int numberOfCommands) {
		CommandStateSpyPtr commandSpy;
		std::vector<CommandStateSpyPtr> commandSpies = std::vector<CommandStateSpyPtr>();

		for (; numberOfCommands > 0; numberOfCommands--)
		{
			CommandStateSpyPtr commandSpy = CommandStateSpy::getNewInstance();
			sut->add(commandSpy);
			commandSpies.push_back(commandSpy);
		}
		return commandSpies;
	}

	CommandQueueImpPtr sut;
	std::vector<CommandStateSpyPtr> commandSpies;
};


#endif //UTILITIES_COMMANDQUEUEIMPTEST_H