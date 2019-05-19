#include "CommandQueueImpTest.h"

/////////////////////////////////////// ADDING & REMOVING COMMANDS /////////////////////////////////////////////
TEST_F(CommandQueueImpTest, 1Command_Added){
	commandSpies = addCommandStateSpiesToQueue(1);

	EXPECT_THAT(commandSpies[0]->getCommandState(), CommandState::Executed);
}
TEST_F(CommandQueueImpTest, 1Command_UndoX1){
	commandSpies = addCommandStateSpiesToQueue(1);

	triggerUndo(1);

	EXPECT_THAT(commandSpies[0]->getCommandState(), CommandState::Undone);
}
TEST_F(CommandQueueImpTest, 1Command_RedoX1){
	commandSpies = addCommandStateSpiesToQueue(1);

	triggerUndo(1);
	triggerRedo(1);

	EXPECT_THAT(commandSpies[0]->getCommandState(), CommandState::Redone);
}

TEST_F(CommandQueueImpTest, 2Commands_UndoX2){
	commandSpies = addCommandStateSpiesToQueue(2);

	triggerUndo(2);

	EXPECT_THAT(commandSpies[0]->getCommandState(), CommandState::Undone);
	EXPECT_THAT(commandSpies[1]->getCommandState(), CommandState::Undone);
}
TEST_F(CommandQueueImpTest, 2Commands_UndoX2RedoX1){
	commandSpies = addCommandStateSpiesToQueue(2);

	triggerUndo(2);
	triggerRedo(1);

	EXPECT_THAT(commandSpies[0]->getCommandState(), CommandState::Redone);
	EXPECT_THAT(commandSpies[1]->getCommandState(), CommandState::Undone);
}
TEST_F(CommandQueueImpTest, Integration_5Commands_UndoX4RedoX1){
	commandSpies = addCommandStateSpiesToQueue(5);

	triggerUndo(4);
	triggerRedo(1);

	EXPECT_THAT(commandSpies[0]->getCommandState(), CommandState::Executed);
	EXPECT_THAT(commandSpies[1]->getCommandState(), CommandState::Redone);
	EXPECT_THAT(commandSpies[2]->getCommandState(), CommandState::Undone);
	EXPECT_THAT(commandSpies[3]->getCommandState(), CommandState::Undone);
	EXPECT_THAT(commandSpies[4]->getCommandState(), CommandState::Undone);
}
TEST_F(CommandQueueImpTest, MoreUndoThanCommands_ShouldThrowOutOfBoundsException){
	commandSpies = addCommandStateSpiesToQueue(2);

	triggerUndo(2);

	ASSERT_THROW(sut->undo(), CommandsOutOfBoundsException*);
}
TEST_F(CommandQueueImpTest, RedoWithoutUndoneCommands_ShouldThrowOutOfBoundsException){
	commandSpies = addCommandStateSpiesToQueue(2);

	ASSERT_THROW(sut->redo(), CommandsOutOfBoundsException*);
}

TEST_F(CommandQueueImpTest, 4CommandsAdded1XUndo1XCommandAdded_RedoNotPossible){
	addCommandStateSpiesToQueue(2);
	triggerUndo(1);

	addCommandStateSpiesToQueue(1);

	ASSERT_THROW(sut->redo(), CommandsOutOfBoundsException*);

}
TEST_F(CommandQueueImpTest, 4CommandsAdded2XUndo1XCommandAdded_RedoNotPossible){
	addCommandStateSpiesToQueue(4);
	triggerUndo(2);

	addCommandStateSpiesToQueue(1);

	ASSERT_THROW(sut->redo(), CommandsOutOfBoundsException*);

}
TEST_F(CommandQueueImpTest, 4CommandsAdded3XUndo1XCommandAdded_RedoNotPossible){
	addCommandStateSpiesToQueue(4);
	triggerUndo(3);

	addCommandStateSpiesToQueue(1);

	ASSERT_THROW(sut->redo(), CommandsOutOfBoundsException*);
}

TEST_F(CommandQueueImpTest, AddingCommadWhichThrowsAModelException_UndoNotPossible){
	sut->add(ThrowingCommandStub::getNewInstance());

	EXPECT_FALSE(sut->undoIsPossible());
}