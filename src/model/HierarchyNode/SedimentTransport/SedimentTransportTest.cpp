#include "SedimentTransportTest.h"

/////////////////////////////////////// VISITOR /////////////////////////////////////////////
TEST_F(SedimentTransportTest, WhenAcceptedPerformedWithInvalidVisitor_ShouldThrowVisitorCastException)
{
	InvalidVisitorDummyPtr visitor = InvalidVisitorDummy::getNewInstance();

	EXPECT_THROW(sut->accept(visitor), VisitorCastException*);
}
TEST_F(SedimentTransportTest, WhenAcceptedPerformedWithValidVisitor_ShouldTriggerTheVisitorToVisitTheSUT)
{
	SedimentTransportVisitorSpyPtr visitor = SedimentTransportVisitorSpy::getNewInstance();

	sut->accept(visitor);

	EXPECT_TRUE(visitor->wasTriggeredToVisit());
	EXPECT_THAT(visitor->getVisitedSedimentTransport(), sut);
}

/////////////////////////////////////// CHILD CHANGING ////////////////////////////////////////
TEST_F(SedimentTransportChildChangedEventSubClass, WhenWaveDynamicIsSet_ShouldRaiseChildReplacedEvent)
{
	WaveDynamicSubClassPtr waveDynamicSubClass = WaveDynamicSubClass::getNewInstance();
	sut->setWaveDynamic(waveDynamicSubClass);

	EXPECT_THAT(childEvent->getLastReceivedObject(), sut);
	EXPECT_THAT(childEvent->getLastReceivedArgs()->getEventType(), ChildEventTypes::Replaced);
	EXPECT_THAT(childEvent->getLastReceivedArgs()->getChangedChild(), waveDynamicSubClass);
	EXPECT_THAT(childEvent->getLastReceivedArgs()->getChildType(), NodeTypes::waveDynamic());
	EXPECT_THAT(childEvent->getLastReceivedArgs()->getRoleName(), SedimentTransportProperties::waveDynamic());
}
TEST_F(SedimentTransportWithEventSubClassesForChild, WhenWaveDynamicIsSet_ShoutAttachItselfToPropertyAndChildEventOfWaveDynamic)
{
	WaveDynamicSubClassPtr waveDynamic = WaveDynamicSubClass::getNewInstance();
	setEventsTo(waveDynamic);

	sut->setWaveDynamic(waveDynamic);

	EXPECT_TRUE(propertyEvent->contains(sut));
	EXPECT_TRUE(childEvent->contains(sut));
}
TEST_F(SedimentTransportWithEventSubClassesForChild, WhenWaveDynamicIsSet_ShouldDetachItselfFromEventsOfOldWaveDynamic)
{
	WaveDynamicSubClassPtr newWaveDynamic = WaveDynamicSubClass::getNewInstance();
	WaveDynamicSubClassPtr oldWaveDynamic = WaveDynamicSubClass::getNewInstance();

	setEventsTo(oldWaveDynamic);
	sut->setWaveDynamic(oldWaveDynamic);

	sut->setWaveDynamic(newWaveDynamic);

	EXPECT_FALSE(childEvent->contains(sut));
	EXPECT_FALSE(propertyEvent->contains(sut));
}

TEST_F(SedimentTransportChildChangedEventSubClass, WhenSedimentIsSet_ShouldRaiseChildReplacedEvent)
{
	SedimentSubClassPtr sedimentSubClass = SedimentSubClass::getNewInstance();
	sut->setSediment(sedimentSubClass);

	EXPECT_THAT(childEvent->getLastReceivedObject(), sut);
	EXPECT_THAT(childEvent->getLastReceivedArgs()->getEventType(), ChildEventTypes::Replaced);
	EXPECT_THAT(childEvent->getLastReceivedArgs()->getChangedChild(), sedimentSubClass);
	EXPECT_THAT(childEvent->getLastReceivedArgs()->getChildType(), NodeTypes::sediment());
	EXPECT_THAT(childEvent->getLastReceivedArgs()->getRoleName(), SedimentTransportProperties::sediment());
}
TEST_F(SedimentTransportWithEventSubClassesForChild, WhenSedimentIsSet_ShoutAttachItselfToPropertyAndChildEventOfSediment)
{
	SedimentSubClassPtr sediment = SedimentSubClass::getNewInstance();
	setEventsTo(sediment);

	sut->setSediment(sediment);

	EXPECT_TRUE(propertyEvent->contains(sut));
	EXPECT_TRUE(childEvent->contains(sut));
}
TEST_F(SedimentTransportWithEventSubClassesForChild, WhenSedimentIsSet_ShouldDetachItselfFromEventsOfOldSediment)
{
	SedimentSubClassPtr newSediment = SedimentSubClass::getNewInstance();
	SedimentSubClassPtr oldSediment= SedimentSubClass::getNewInstance();

	setEventsTo(oldSediment);
	sut->setSediment(oldSediment);

	sut->setSediment(newSediment);

	EXPECT_FALSE(childEvent->contains(sut));
	EXPECT_FALSE(propertyEvent->contains(sut));
}

/////////////////////////////////////// CHILD BINDING /////////////////////////////////////////////
TEST_F(SedimentTransportTest, WhenAskedIfCanBindWithInvalidNodeType_ShouldReturnFalse)
{
	EXPECT_FALSE(sut->canBind(ReturnsASpecificTypeStub::getNewInstance("invalid")));
}
TEST_F(SedimentTransportTest, WhenAskedIfCanBindWithWaveDynamicType_ShouldReturnTrue)
{
	EXPECT_TRUE(sut->canBind(ReturnsASpecificTypeStub::getNewInstance(NodeTypes::waveDynamic())));
}
TEST_F(SedimentTransportTest, WhenAskedIfCanBindWithSedimentType_ShouldReturnTrue)
{
	EXPECT_TRUE(sut->canBind(ReturnsASpecificTypeStub::getNewInstance(NodeTypes::sediment())));
}

/////////////////////////////////////// CHILD PROPERTIES /////////////////////////////////////////////
TEST_F(SedimentTransportChildsWithPropertiesSet, WaveDynamicName)
{
	EXPECT_THAT(sut->getWaveDynamicName(), testing::StrEq(waveDynamic->getName()));
}
TEST_F(SedimentTransportChildsWithPropertiesSet, SedimentName)
{
	EXPECT_THAT(sut->getSedimentName(), testing::StrEq(sediment->getName()));
}