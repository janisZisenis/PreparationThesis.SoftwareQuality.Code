#include "SedimentTest.h"

/////////////////////////////////////// VISITOR /////////////////////////////////////////////
TEST_F(SedimentTest, WhenAcceptedPerformedWithInvalidVisitor_ShouldThrowVisitorCastException)
{
	InvalidVisitorDummyPtr visitor = InvalidVisitorDummy::getNewInstance();

	EXPECT_THROW(sut->accept(visitor), VisitorCastException*);
}
TEST_F(SedimentTest, WhenAcceptedPerformedWithValidVisitor_ShouldTriggerTheVisitorToVisitTheSUT)
{
	SedimentVisitorSpyPtr visitor = SedimentVisitorSpy::getNewInstance();

	sut->accept(visitor);

	EXPECT_TRUE(visitor->wasTriggeredToVisit());
	EXPECT_THAT(visitor->getVisitedCoordinateSystem(), sut);
}

/////////////////////////////////////// PROPERTY CHANGING ////////////////////////////////////////
TEST_F(SedimentPropertyChangedEventSubClass, WhenDensityIsSet_ShouldTriggerThePropertyChangedEventToNotifyListeners)
{
	sut->setDensity(1000.0);

	EXPECT_THAT(evt->getLastReceivedObject(), sut);
	EXPECT_THAT(evt->getLastReceivedArgs()->getPropertyName(), testing::StrEq(SedimentProperties::density()));
}

/////////////////////////////////////// CHILD BINDING /////////////////////////////////////////////
TEST_F(SedimentTest, WhenAskedIfCanBindWithAnyNodeType_ShouldReturnFalse)
{
	EXPECT_FALSE(sut->canBind(ReturnsASpecificTypeStub::getNewInstance("anyType")));
}