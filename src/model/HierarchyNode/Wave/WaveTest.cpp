#include "WaveTest.h"

/////////////////////////////////////// VISITOR /////////////////////////////////////////////
TEST_F(WaveTest, WhenAcceptedPerformedWithInvalidVisitor_ShouldThrowVisitorCastException)
{
	InvalidVisitorDummyPtr visitor = InvalidVisitorDummy::getNewInstance();

	EXPECT_THROW(sut->accept(visitor), VisitorCastException*);
}
TEST_F(WaveTest, WhenAcceptedPerformedWithValidVisitor_ShouldTriggerTheVisitorToVisitTheSUT)
{
	WaveVisitorSpyPtr visitor = WaveVisitorSpy::getNewInstance();

	sut->accept(visitor);

	EXPECT_TRUE(visitor->wasTriggeredToVisit());
	EXPECT_THAT(visitor->getVisitedWave(), sut);
}

/////////////////////////////////////// PROPERTY CHANGING ////////////////////////////////////////
TEST_F(WavePropertyChangedEventSubClass, WhenLengthIsSet_ShouldTriggerThePropertyChangedEventToNotifyListeners)
{
	sut->setLength(50.0);

	EXPECT_THAT(evt->getLastReceivedObject(), sut);
	EXPECT_THAT(evt->getLastReceivedArgs()->getPropertyName(), testing::StrEq(WaveProperties::waveLength()));
}
TEST_F(WavePropertyChangedEventSubClass, WhenPeriodIsSet_ShouldTriggerThePropertyChangedEventToNotifyListeners)
{
	sut->setPeriod(7.5);

	EXPECT_THAT(evt->getLastReceivedObject(), sut);
	EXPECT_THAT(evt->getLastReceivedArgs()->getPropertyName(), testing::StrEq(WaveProperties::wavePeriod()));
}
TEST_F(WavePropertyChangedEventSubClass, WhenHeightIsSet_ShouldTriggerThePropertyChangedEventToNotifyListeners)
{
	sut->setHeight(7.5);

	EXPECT_THAT(evt->getLastReceivedObject(), sut);
	EXPECT_THAT(evt->getLastReceivedArgs()->getPropertyName(), testing::StrEq(WaveProperties::waveHeight()));
}
TEST_F(WavePropertyChangedEventSubClass, WhenWaterDepthIsSet_ShouldTriggerThePropertyChangedEventToNotifyListeners)
{
	sut->setWaterDepth(10.9);

	EXPECT_THAT(evt->getLastReceivedObject(), sut);
	EXPECT_THAT(evt->getLastReceivedArgs()->getPropertyName(), testing::StrEq(WaveProperties::waterDepth()));
}

/////////////////////////////////////// CHILD BINDING /////////////////////////////////////////////
TEST_F(WaveTest, WhenAskedIfCanBindWithAnyNodeType_ShouldReturnFalse)
{
	EXPECT_FALSE(sut->canBind(ReturnsASpecificTypeStub::getNewInstance("anyType")));
}

/////////////////////////////////////// MATHEMATICS /////////////////////////////////////////////
TEST_F(WaveWithPropertiesSet, AngularWaveNumber)
{
	double result = sut->getAngularNumber();
	double expectedResult = 0.0698;

	actualEqualsExpected(result, expectedResult);
}
TEST_F(WaveWithPropertiesSet, AngularWaveFrequency)
{
	double result = sut->getAngularFrequency();
	double expectedResult = 0.6427;

	actualEqualsExpected(result, expectedResult);
}