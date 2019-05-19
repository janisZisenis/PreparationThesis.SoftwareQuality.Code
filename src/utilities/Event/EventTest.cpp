#include "EventTest.h"

///////////////////////////////////////// NOTIFY LISTENERS /////////////////////////////////////////
TEST_F(SomeEventListersAttached, WhenNotifyListenersPerformed_ShouldPassTheSenderAndArgumentsToListeners)
{
	sut->notifyListeners(objectDummy, argsDummy);

	expectListenerWasTriggeredToHandleWithCorrectArguments(firstListenerSpy);
	expectListenerWasTriggeredToHandleWithCorrectArguments(secondListenerSpy);
	expectListenerWasTriggeredToHandleWithCorrectArguments(thirdListenerSpy);
}
TEST_F(SomeEventListersAttached, WhenNotifyListenersPerformedAfterDetachingEventListener_ShouldPassTheSenderAndArgumentsToAttachedListeners)
{
	sut->detach(firstListenerSpy);
	sut->detach(secondListenerSpy);

	sut->notifyListeners(objectDummy, argsDummy);

	expectListenerWasNotTriggeredToHandleEvent(firstListenerSpy);
	expectListenerWasNotTriggeredToHandleEvent(secondListenerSpy);
	expectListenerWasTriggeredToHandleWithCorrectArguments(thirdListenerSpy);
}
TEST_F(SomeEventListersAttachedMoreThanOnce, WhenNotifyListenersPerformedAfterDetachingEventListener_ShouldPassTheSenderAndArgumentsToAttachedListeners)
{
	sut->detach(firstListenerSpy);
	sut->detach(secondListenerSpy);

	sut->notifyListeners(objectDummy, argsDummy);

	expectListenerWasNotTriggeredToHandleEvent(firstListenerSpy);
	expectListenerWasNotTriggeredToHandleEvent(secondListenerSpy);
	expectListenerWasTriggeredToHandleWithCorrectArguments(thirdListenerSpy);
}
TEST_F(SomeEventListersAttached, WhenNotifyListenersPerformedAfterListenerWasDeleted_ShouldNotifyAllLockableEventListener)
{
	secondListenerSpy.reset();

	sut->notifyListeners(objectDummy, argsDummy);

	expectListenerWasTriggeredToHandleWithCorrectArguments(firstListenerSpy);
	expectListenerWasTriggeredToHandleWithCorrectArguments(thirdListenerSpy);
}
TEST_F(OtherEventContainsSomeListeners, WhenNotifyListenersIsPerformedAfterAppendingListenersOfAnotherEvent_ShouldNotifyAllListeners)
{
	sut->appendListenersOf(otherEvent);
	sut->notifyListeners(objectDummy, argsDummy);

	expectListenerWasTriggeredToHandleWithCorrectArguments(firstListenerSpy);
	expectListenerWasTriggeredToHandleWithCorrectArguments(secondListenerSpy);
	expectListenerWasTriggeredToHandleWithCorrectArguments(thirdListenerSpy);

	expectListenerWasTriggeredToHandleWithCorrectArguments(firstOtherListenerSpy);
	expectListenerWasTriggeredToHandleWithCorrectArguments(secondOtherListenerSpy);
}
TEST_F(OtherEventContainsTheSameListeners, WhenNotifyListenersIsPerformedAfterAppendingListenersOfAnotherEvent_ShouldNotifyAllListenersOnce)
{
	sut->appendListenersOf(otherEvent);
	sut->notifyListeners(objectDummy, argsDummy);

	expectListenerWasTriggeredToHandleWithCorrectArguments(firstListenerSpy);
	EXPECT_THAT(firstListenerSpy->getTimesTriggeredToHandleEvent(), 1);

	expectListenerWasTriggeredToHandleWithCorrectArguments(secondListenerSpy);
	EXPECT_THAT(secondListenerSpy->getTimesTriggeredToHandleEvent(), 1);

	expectListenerWasTriggeredToHandleWithCorrectArguments(thirdListenerSpy);
	EXPECT_THAT(thirdListenerSpy->getTimesTriggeredToHandleEvent(), 1);
}
