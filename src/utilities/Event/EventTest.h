#ifndef UTILITIES_EVENTTEST_H
#define UTILITIES_EVENTTEST_H

#include "gmock/gmock.h"
#include "Event.h"
#include "EventArgsMocks.h"
#include "EventListenerMocks.h"
#include "utilities/Object/ObjectMocks.h"

class EventTest : public testing::Test
{
protected:
	virtual void SetUp() override {
        sut = Event<EventArgsDummy>::getNewInstance();
	}
	EventPtr<EventArgsDummy> sut;
};

class SomeEventListersAttached : public EventTest
{
protected:
	virtual void SetUp() override
	{
		EventTest::SetUp();

		objectDummy = ObjectDummy::getNewInstance();
		argsDummy = EventArgsDummy::getNewInstance();

		firstListenerSpy = EventListenerSpy<EventArgsDummy>::getNewInstance();
		secondListenerSpy = EventListenerSpy<EventArgsDummy>::getNewInstance();
		thirdListenerSpy = EventListenerSpy<EventArgsDummy>::getNewInstance();

		sut->attach(firstListenerSpy);
		sut->attach(secondListenerSpy);
		sut->attach(thirdListenerSpy);
	}
	virtual void expectListenerWasTriggeredToHandleWithCorrectArguments(EventListenerSpyPtr<EventArgsDummy> listener)
	{
		EXPECT_THAT(listener->getReceivedObject(), objectDummy);
		EXPECT_THAT(listener->getReceivedArgs(), argsDummy);
	}
	virtual void expectListenerWasNotTriggeredToHandleEvent(EventListenerSpyPtr<EventArgsDummy> listener)
	{
		EXPECT_THAT(listener->getReceivedObject(), testing::IsNull());
		EXPECT_THAT(listener->getReceivedArgs(), testing::IsNull());
	}

	EventListenerSpyPtr<EventArgsDummy> firstListenerSpy;
	EventListenerSpyPtr<EventArgsDummy> secondListenerSpy;
	EventListenerSpyPtr<EventArgsDummy> thirdListenerSpy;

	ObjectDummyPtr objectDummy;
	EventArgsDummyPtr argsDummy;
};

class SomeEventListersAttachedMoreThanOnce : public SomeEventListersAttached
{
protected:
	virtual void SetUp() override
	{
		SomeEventListersAttached::SetUp();

		sut->attach(firstListenerSpy);
		sut->attach(firstListenerSpy);
		sut->attach(firstListenerSpy);

		sut->attach(secondListenerSpy);
		sut->attach(secondListenerSpy);
		sut->attach(secondListenerSpy);
		sut->attach(secondListenerSpy);
	}
};

class OtherEventContainsSomeListeners : public SomeEventListersAttached
{
protected:
	virtual void SetUp() override
	{
		SomeEventListersAttached::SetUp();

		otherEvent = Event<EventArgsDummy>::getNewInstance();

		firstOtherListenerSpy = EventListenerSpy<EventArgsDummy>::getNewInstance();
		secondOtherListenerSpy = EventListenerSpy<EventArgsDummy>::getNewInstance();
		otherEvent->attach(firstOtherListenerSpy);
		otherEvent->attach(secondOtherListenerSpy);
	}
	EventPtr<EventArgsDummy> otherEvent;
	EventListenerSpyPtr<EventArgsDummy> firstOtherListenerSpy;
	EventListenerSpyPtr<EventArgsDummy> secondOtherListenerSpy;
};

class OtherEventContainsTheSameListeners : public SomeEventListersAttached
{
protected:
	virtual void SetUp() override
	{
		SomeEventListersAttached::SetUp();

		otherEvent = Event<EventArgsDummy>::getNewInstance();

		otherEvent->attach(firstListenerSpy);
		otherEvent->attach(secondListenerSpy);
		otherEvent->attach(thirdListenerSpy);
	}
	EventPtr<EventArgsDummy> otherEvent;
};


#endif //UTILITIES_EVENTTEST_H