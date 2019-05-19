#include "WaterTest.h"

/////////////////////////////////////// VISITOR /////////////////////////////////////////////
TEST_F(WaterTest, WhenAcceptedPerformedWithInvalidVisitor_ShouldThrowVisitorCastException)
{
	InvalidVisitorDummyPtr visitor = InvalidVisitorDummy::getNewInstance();

	EXPECT_THROW(sut->accept(visitor), VisitorCastException*);
}
TEST_F(WaterTest, WhenAcceptedPerformedWithValidVisitor_ShouldTriggerTheVisitorToVisitTheSUT)
{
	WaterVisitorSpyPtr visitor = WaterVisitorSpy::getNewInstance();

	sut->accept(visitor);

	EXPECT_TRUE(visitor->wasTriggeredToVisit());
	EXPECT_THAT(visitor->getVisitedWater(), sut);
}

/////////////////////////////////////// PROPERTY CHANGING ////////////////////////////////////////
TEST_F(WaterPropertyChangedEventSubClass, WhenDensityIsSet_ShouldTriggerThePropertyChangedEventToNotifyListeners)
{
	sut->setDensity(1000.0);

	EXPECT_THAT(evt->getLastReceivedObject(), sut);
	EXPECT_THAT(evt->getLastReceivedArgs()->getPropertyName(), testing::StrEq(WaterProperties::density()));
}
TEST_F(WaterPropertyChangedEventSubClass, WhenViscosityIsSet_ShouldTriggerThePropertyChangedEventToNotifyListeners)
{
	sut->setViscosity(1000.0);

	EXPECT_THAT(evt->getLastReceivedObject(), sut);
	EXPECT_THAT(evt->getLastReceivedArgs()->getPropertyName(), testing::StrEq(WaterProperties::viscosity()));
}

/////////////////////////////////////// CHILD BINDING /////////////////////////////////////////////
TEST_F(WaterTest, WhenAskedIfCanBindWithAnyNodeType_ShouldReturnFalse)
{
	EXPECT_FALSE(sut->canBind(ReturnsASpecificTypeStub::getNewInstance("anyType")));
}