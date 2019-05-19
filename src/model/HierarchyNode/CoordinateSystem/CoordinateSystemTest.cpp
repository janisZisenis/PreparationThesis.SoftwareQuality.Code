#include "CoordinateSystemTest.h"

/////////////////////////////////////// VISITOR /////////////////////////////////////////////
TEST_F(CoordinateSystemTest, WhenAcceptedPerformedWithInvalidVisitor_ShouldThrowVisitorCastException)
{
	InvalidVisitorDummyPtr visitor = InvalidVisitorDummy::getNewInstance();

	EXPECT_THROW(sut->accept(visitor), VisitorCastException*);
}
TEST_F(CoordinateSystemTest, WhenAcceptedPerformedWithValidVisitor_ShouldTriggerTheVisitorToVisitTheSUT)
{
	CoordinateSystemVisitorSpyPtr visitor = CoordinateSystemVisitorSpy::getNewInstance();

	sut->accept(visitor);

	EXPECT_TRUE(visitor->wasTriggeredToVisit());
	EXPECT_THAT(visitor->getVisitedCoordinateSystem(), sut);
}

/////////////////////////////////////// PROPERTY CHANGING ////////////////////////////////////////
TEST_F(CoordinateSystemPropertyChangedEventSubClass, WhenXIsSet_ShouldTriggerThePropertyChangedEventToNotifyListeners)
{
	sut->setX(5.0);

	EXPECT_THAT(evt->getLastReceivedObject(), sut);
	EXPECT_THAT(evt->getLastReceivedArgs()->getPropertyName(), testing::StrEq(CoordinateSystemProperties::x()));
}
TEST_F(CoordinateSystemPropertyChangedEventSubClass, WhenTIsSet_ShouldTriggerThePropertyChangedEventToNotifyListeners)
{
	sut->setT(5.0);

	EXPECT_THAT(evt->getLastReceivedObject(), sut);
	EXPECT_THAT(evt->getLastReceivedArgs()->getPropertyName(), testing::StrEq(CoordinateSystemProperties::t()));
}
TEST_F(CoordinateSystemPropertyChangedEventSubClass, WhenZIsSet_ShouldTriggerThePropertyChangedEventToNotifyListeners)
{
	sut->setZ(5.0);

	EXPECT_THAT(evt->getLastReceivedObject(), sut);
	EXPECT_THAT(evt->getLastReceivedArgs()->getPropertyName(), testing::StrEq(CoordinateSystemProperties::z()));
}

/////////////////////////////////////// CHILD BINDING /////////////////////////////////////////////
TEST_F(CoordinateSystemTest, WhenAskedIfCanBindWithAnyNodeType_ShouldReturnFalse)
{
	EXPECT_FALSE(sut->canBind(ReturnsASpecificTypeStub::getNewInstance("anyType")));
}