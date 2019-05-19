#include "PileTest.h"

/////////////////////////////////////// VISITOR /////////////////////////////////////////////
TEST_F(PileTest, WhenAcceptedPerformedWithInvalidVisitor_ShouldThrowVisitorCastException)
{
	InvalidVisitorDummyPtr visitor = InvalidVisitorDummy::getNewInstance();

	EXPECT_THROW(sut->accept(visitor), VisitorCastException*);
}
TEST_F(PileTest, WhenAcceptedPerformedWithValidVisitor_ShouldTriggerTheVisitorToVisitTheSUT)
{
	PileVisitorSpyPtr visitor = PileVisitorSpy::getNewInstance();

	sut->accept(visitor);

	EXPECT_TRUE(visitor->wasTriggeredToVisit());
	EXPECT_THAT(visitor->getVisitedPile(), sut);
}

/////////////////////////////////////// PROPERTY CHANGING ////////////////////////////////////////
TEST_F(PilePropertyChangedEventSubClass, WhenDiameterIsSet_ShouldTriggerThePropertyChangedEventToNotifyListeners)
{
	sut->setDiameter(5.0);

	EXPECT_THAT(evt->getLastReceivedObject(), sut);
	EXPECT_THAT(evt->getLastReceivedArgs()->getPropertyName(), testing::StrEq(PileProperties::diameter()));
}

/////////////////////////////////////// CHILD BINDING /////////////////////////////////////////////
TEST_F(PileTest, WhenAskedIfCanBindWithAnyNodeType_ShouldReturnFalse)
{
	EXPECT_FALSE(sut->canBind(ReturnsASpecificTypeStub::getNewInstance("anyType")));
}