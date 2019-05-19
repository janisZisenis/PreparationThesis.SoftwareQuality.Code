#include "MorisonTest.h"

/////////////////////////////////////// VISITOR /////////////////////////////////////////////
TEST_F(MorisonTest, WhenAcceptedPerformedWithInvalidVisitor_ShouldThrowVisitorCastException)
{
	InvalidVisitorDummyPtr visitor = InvalidVisitorDummy::getNewInstance();

	EXPECT_THROW(sut->accept(visitor), VisitorCastException*);
}
TEST_F(MorisonTest, WhenAcceptedPerformedWithValidVisitor_ShouldTriggerTheVisitorToVisitTheSUT)
{
	MorisonVisitorSpyPtr visitor = MorisonVisitorSpy::getNewInstance();

	sut->accept(visitor);

	EXPECT_TRUE(visitor->wasTriggeredToVisit());
	EXPECT_THAT(visitor->getVisitedMorison(), sut);
}

/////////////////////////////////////// CHILD CHANGING ////////////////////////////////////////
TEST_F(MorisonChildChangedEventSubClass, WhenWaveDynamicIsSet_ShouldRaiseChildReplacedEvent)
{
	WaveDynamicSubClassPtr waveDynamicSubClass = WaveDynamicSubClass::getNewInstance();
	sut->setWaveDynamic(waveDynamicSubClass);

	EXPECT_THAT(childEvent->getLastReceivedObject(), sut);
	EXPECT_THAT(childEvent->getLastReceivedArgs()->getEventType(), ChildEventTypes::Replaced);
	EXPECT_THAT(childEvent->getLastReceivedArgs()->getChangedChild(), waveDynamicSubClass);
	EXPECT_THAT(childEvent->getLastReceivedArgs()->getChildType(), NodeTypes::waveDynamic());
	EXPECT_THAT(childEvent->getLastReceivedArgs()->getRoleName(), MorisonProperties::waveDynamic());
}
TEST_F(MorisonWithEventSubClassesForChild, WhenWaveDynamicIsSet_ShoutAttachItselfToPropertyAndChildEventOfWaveDynamic)
{
	WaveDynamicSubClassPtr waveDynamic = WaveDynamicSubClass::getNewInstance();
	setEventsTo(waveDynamic);

	sut->setWaveDynamic(waveDynamic);

	EXPECT_TRUE(propertyEvent->contains(sut));
	EXPECT_TRUE(childEvent->contains(sut));
}
TEST_F(MorisonWithEventSubClassesForChild, WhenWaveDynamicIsSet_ShouldDetachItselfFromEventsOfOldWaveDynamic)
{
	WaveDynamicSubClassPtr newWaveDynamic = WaveDynamicSubClass::getNewInstance();
	WaveDynamicSubClassPtr oldWaveDynamic = WaveDynamicSubClass::getNewInstance();

	setEventsTo(oldWaveDynamic);
	sut->setWaveDynamic(oldWaveDynamic);

	sut->setWaveDynamic(newWaveDynamic);

	EXPECT_FALSE(childEvent->contains(sut));
	EXPECT_FALSE(propertyEvent->contains(sut));
}

TEST_F(MorisonChildChangedEventSubClass, WhenPileIsSet_ShouldRaiseChildReplacedEvent)
{
	PileSubClassPtr pileSubClass = PileSubClass::getNewInstance();
	sut->setPile(pileSubClass);

	EXPECT_THAT(childEvent->getLastReceivedObject(), sut);
	EXPECT_THAT(childEvent->getLastReceivedArgs()->getEventType(), ChildEventTypes::Replaced);
	EXPECT_THAT(childEvent->getLastReceivedArgs()->getChangedChild(), pileSubClass);
	EXPECT_THAT(childEvent->getLastReceivedArgs()->getChildType(), NodeTypes::pile());
	EXPECT_THAT(childEvent->getLastReceivedArgs()->getRoleName(), MorisonProperties::pile());
}
TEST_F(MorisonWithEventSubClassesForChild, WhenPileIsSet_ShoutAttachItselfToPropertyAndChildEventOfPile)
{
	PileSubClassPtr pile = PileSubClass::getNewInstance();
	setEventsTo(pile);

	sut->setPile(pile);

	EXPECT_TRUE(propertyEvent->contains(sut));
	EXPECT_TRUE(childEvent->contains(sut));
}
TEST_F(MorisonWithEventSubClassesForChild, WhenPileIsSet_ShouldDetachItselfFromEventsOfOldPile)
{
	PileSubClassPtr newPile = PileSubClass::getNewInstance();
	PileSubClassPtr oldPile= PileSubClass::getNewInstance();

	setEventsTo(oldPile);
	sut->setPile(oldPile);

	sut->setPile(newPile);

	EXPECT_FALSE(childEvent->contains(sut));
	EXPECT_FALSE(propertyEvent->contains(sut));
}

/////////////////////////////////////// CHILD BINDING /////////////////////////////////////////////
TEST_F(MorisonTest, WhenAskedIfCanBindWithInvalidNodeType_ShouldReturnFalse)
{
	EXPECT_FALSE(sut->canBind(ReturnsASpecificTypeStub::getNewInstance("invalid")));
}
TEST_F(MorisonTest, WhenAskedIfCanBindWithWaveDynamicType_ShouldReturnTrue)
{
	EXPECT_TRUE(sut->canBind(ReturnsASpecificTypeStub::getNewInstance(NodeTypes::waveDynamic())));
}
TEST_F(MorisonTest, WhenAskedIfCanBindWithPileType_ShouldReturnTrue)
{
	EXPECT_TRUE(sut->canBind(ReturnsASpecificTypeStub::getNewInstance(NodeTypes::pile())));
}

/////////////////////////////////////// CHILD PROPERTIES /////////////////////////////////////////////
TEST_F(MorisonChildsWithPropertiesSet, WaveDynamicName)
{
	EXPECT_THAT(sut->getWaveDynamicName(), testing::StrEq(waveDynamic->getName()));
}
TEST_F(MorisonChildsWithPropertiesSet, PileName)
{
	EXPECT_THAT(sut->getPileName(), testing::StrEq(pile->getName()));
}

