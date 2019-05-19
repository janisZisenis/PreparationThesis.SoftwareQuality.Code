#include "WaveDynamicTest.h"
#include "model/HierarchyNode/HierarchyNodeMocks.h"

/////////////////////////////////////// VISITOR /////////////////////////////////////////////
TEST_F(WaveDynamicTest, WhenAcceptedPerformedWithInvalidVisitor_ShouldThrowVisitorCastException)
{
	InvalidVisitorDummyPtr visitor = InvalidVisitorDummy::getNewInstance();

	EXPECT_THROW(sut->accept(visitor), VisitorCastException*);
}
TEST_F(WaveDynamicTest, WhenAcceptedPerformedWithValidVisitor_ShouldTriggerTheVisitorToVisitTheSUT)
{
	WaveDynamicVisitorSpyPtr visitor = WaveDynamicVisitorSpy::getNewInstance();

	sut->accept(visitor);

	EXPECT_TRUE(visitor->wasTriggeredToVisit());
	EXPECT_THAT(visitor->getVisitedWaveDynamic(), sut);
}

/////////////////////////////////////// CHILD CHANGING ////////////////////////////////////////
TEST_F(WaveDynamicWithEventSubClasses, WhenCoordinateSystemIsSet_ShouldRaiseChildReplacedEvent)
{
	CoordinateSystemSubClassPtr coordinateSystemSubClass = CoordinateSystemSubClass::getNewInstance();
	sut->setCoordinateSystem(coordinateSystemSubClass);

	EXPECT_THAT(childEvent->getLastReceivedObject(), sut);
	EXPECT_THAT(childEvent->getLastReceivedArgs()->getEventType(), ChildEventTypes::Replaced);
	EXPECT_THAT(childEvent->getLastReceivedArgs()->getChangedChild(), coordinateSystemSubClass);
	EXPECT_THAT(childEvent->getLastReceivedArgs()->getChildType(), NodeTypes::coordinateSystem());
	EXPECT_THAT(childEvent->getLastReceivedArgs()->getRoleName(), WaveDynamicProperties::coordinateSystem());
}
TEST_F(WaveDynamicWithEventSubClassesForChild, WhenCoordinateSystemIsSet_ShoutAttachItselfToPropertyAndChildEventOfCoordinateSystem)
{
	CoordinateSystemSubClassPtr coordinateSystem = CoordinateSystemSubClass::getNewInstance();
	setEventsTo(coordinateSystem);

	sut->setCoordinateSystem(coordinateSystem);

	EXPECT_TRUE(propertyEvent->contains(sut));
	EXPECT_TRUE(childEvent->contains(sut));
}
TEST_F(WaveDynamicWithEventSubClassesForChild, WhenCoordinateSystemIsSet_ShouldDetachItselfFromEventsOfOldCoordinateSystem)
{
	CoordinateSystemSubClassPtr newCoordinateSystem = CoordinateSystemSubClass::getNewInstance();
	CoordinateSystemSubClassPtr oldCoordinateSystem = CoordinateSystemSubClass::getNewInstance();
	
	setEventsTo(oldCoordinateSystem);
	sut->setCoordinateSystem(oldCoordinateSystem);

	sut->setCoordinateSystem(newCoordinateSystem);

	EXPECT_FALSE(childEvent->contains(sut));
	EXPECT_FALSE(propertyEvent->contains(sut));
}

TEST_F(WaveDynamicWithEventSubClasses, WhenWaterIsSet_ShouldRaiseChildReplacedEvent)
{
	WaterSubClassPtr waterSubClass = WaterSubClass::getNewInstance();
	sut->setWater(waterSubClass);

	EXPECT_THAT(childEvent->getLastReceivedObject(), sut);
	EXPECT_THAT(childEvent->getLastReceivedArgs()->getEventType(), ChildEventTypes::Replaced);
	EXPECT_THAT(childEvent->getLastReceivedArgs()->getChangedChild(), waterSubClass);
	EXPECT_THAT(childEvent->getLastReceivedArgs()->getChildType(), NodeTypes::water());
	EXPECT_THAT(childEvent->getLastReceivedArgs()->getRoleName(), WaveDynamicProperties::water());
}
TEST_F(WaveDynamicWithEventSubClassesForChild, WhenWaterIsSet_ShoutAttachItselfToPropertyAndChildEventOfWater)
{
	WaterSubClassPtr water = WaterSubClass::getNewInstance();
	setEventsTo(water);

	sut->setWater(water);

	EXPECT_TRUE(propertyEvent->contains(sut));
	EXPECT_TRUE(childEvent->contains(sut));
}
TEST_F(WaveDynamicWithEventSubClassesForChild, WhenWaterIsSet_ShouldDetachItselfFromEventsOfOldWater)
{
	WaterSubClassPtr newWater = WaterSubClass::getNewInstance();
	WaterSubClassPtr oldWater = WaterSubClass::getNewInstance();

	setEventsTo(oldWater);
	sut->setWater(oldWater);

	sut->setWater(newWater);

	EXPECT_FALSE(childEvent->contains(sut));
	EXPECT_FALSE(propertyEvent->contains(sut));
}

TEST_F(WaveDynamicWithEventSubClasses, WhenWaveIsSet_ShouldRaiseChildReplacedEvent)
{
	WaveSubClassPtr waveSubClass = WaveSubClass::getNewInstance();
	sut->setWave(waveSubClass);

	EXPECT_THAT(childEvent->getLastReceivedObject(), sut);
	EXPECT_THAT(childEvent->getLastReceivedArgs()->getEventType(), ChildEventTypes::Replaced);
	EXPECT_THAT(childEvent->getLastReceivedArgs()->getChangedChild(), waveSubClass);
	EXPECT_THAT(childEvent->getLastReceivedArgs()->getChildType(), NodeTypes::wave());
	EXPECT_THAT(childEvent->getLastReceivedArgs()->getRoleName(), WaveDynamicProperties::wave());
}
TEST_F(WaveDynamicWithEventSubClassesForChild, WhenWaveIsSet_ShoutAttachItselfToPropertyAndChildEventOfWave)
{
	WaveSubClassPtr wave = WaveSubClass::getNewInstance();
	setEventsTo(wave);

	sut->setWave(wave);

	EXPECT_TRUE(propertyEvent->contains(sut));
	EXPECT_TRUE(childEvent->contains(sut));
}
TEST_F(WaveDynamicWithEventSubClassesForChild, WhenWaveIsSet_ShouldDetachItselfFromEventsOfOldWave)
{
	WaveSubClassPtr newWave = WaveSubClass::getNewInstance();
	WaveSubClassPtr oldWave = WaveSubClass::getNewInstance();

	setEventsTo(oldWave);
	sut->setWave(oldWave);

	sut->setWave(newWave);

	EXPECT_FALSE(childEvent->contains(sut));
	EXPECT_FALSE(propertyEvent->contains(sut));
}

/////////////////////////////////////// CHILD BINDING /////////////////////////////////////////////
TEST_F(WaveDynamicTest, WhenAskedIfCanBindWithInvalidNodeType_ShouldReturnFalse)
{
	EXPECT_FALSE(sut->canBind(ReturnsASpecificTypeStub::getNewInstance("invalid")));
}
TEST_F(WaveDynamicTest, WhenAskedIfCanBindWithCoordinateSystemType_ShouldReturnTrue)
{
	EXPECT_TRUE(sut->canBind(ReturnsASpecificTypeStub::getNewInstance(NodeTypes::coordinateSystem())));
}
TEST_F(WaveDynamicTest, WhenAskedIfCanBindWithWaterType_ShouldReturnTrue)
{
	EXPECT_TRUE(sut->canBind(ReturnsASpecificTypeStub::getNewInstance(NodeTypes::water())));
}
TEST_F(WaveDynamicTest, WhenAskedIfCanBindWithWaveType_ShouldReturnTrue)
{
	EXPECT_TRUE(sut->canBind(ReturnsASpecificTypeStub::getNewInstance(NodeTypes::wave())));
}

/////////////////////////////////////// MATHEMATICS /////////////////////////////////////////////
TEST_F(WaveDynamicChildsWithPropertiesSet, WaterSurfaceDisplacement)
{
	double result = sut->getWaterSurfaceDisplacement();
	double expectedResult = 0.2465;

	actualEqualsExpected(result, expectedResult);
}
TEST_F(WaveDynamicChildsWithPropertiesSet, SpatialWaterProfile)
{
	double result = sut->getSpatialWaterProfile(0.357);
	double expectedResult = 0.2391;

	actualEqualsExpected(result, expectedResult);
}
TEST_F(WaveDynamicChildsWithPropertiesSet, TimeWaterProfile)
{
	double result = sut->getTimeWaterProfile(3.5);
	double expectedResult = -0.0472;

	actualEqualsExpected(result, expectedResult);
}

TEST_F(WaveDynamicChildsWithPropertiesSet, StaticPressure)
{
	double result = sut->getStaticPressure();
	double expectedResult = 50.2763 ;

	actualEqualsExpected(result, expectedResult);
}
TEST_F(WaveDynamicChildsWithPropertiesSet, calcStaticPressureBySelectedDepth)
{
	double result = sut->calcStaticPressureBySelectedDepth(-7.5);
	double expectedResult = 75.4144;

	actualEqualsExpected(result, expectedResult);
}
TEST_F(WaveDynamicChildsWithPropertiesSet, PressureResponseFactor)
{
	double result = sut->getPressureResponseCoefficient();
	double expectedResult = 0.8467;

	actualEqualsExpected(result, expectedResult);
}
TEST_F(WaveDynamicChildsWithPropertiesSet, DynamicPressure)
{
	double result = sut->getDynamicPressure();
	double expectedResult = 2.0987;

	actualEqualsExpected(result, expectedResult);
}
TEST_F(WaveDynamicChildsWithPropertiesSet, calcDynamicPressureBySelectedDepth)
{
	double result = sut->calcDynamicPressureBySelectedDepth(-7.5);
	double expectedResult = 2.0072;

	actualEqualsExpected(result, expectedResult);
}
TEST_F(WaveDynamicChildsWithPropertiesSet, TotalPressure)
{
	double result = sut->getTotalPressure();
	double expectedResult = 52.3750;

	actualEqualsExpected(result, expectedResult);
}
TEST_F(WaveDynamicChildsWithPropertiesSet, calcTotalPressureBySelectedDepth)
{
	double result = sut->calcTotalPressureBySelectedDepth(-7.5);
	double expectedResult = 77.4216;

	actualEqualsExpected(result, expectedResult);
}

/////////////////////////////////////// CHILD PROPERTIES /////////////////////////////////////////////
TEST_F(WaveDynamicChildsWithPropertiesSet, CoordinateSystemName)
{
	EXPECT_THAT(sut->getCoordinateSystemName(), testing::StrEq(coord->getName()));
}

TEST_F(WaveDynamicChildsWithPropertiesSet, WaterName)
{
	EXPECT_THAT(sut->getWaterName(), testing::StrEq(water->getName()));
}

TEST_F(WaveDynamicChildsWithPropertiesSet, WaveName)
{
	EXPECT_THAT(sut->getWaveName(), testing::StrEq(wave->getName()));
}
TEST_F(WaveDynamicChildsWithPropertiesSet, AngularWaveNumber)
{
	double result = sut->getAngularWaveNumber();
	double expectedResult = wave->getAngularNumber();

	actualEqualsExpected(result, expectedResult);
}
TEST_F(WaveDynamicChildsWithPropertiesSet, AngularWaveFrequency)
{
	double result = sut->getAngularWaveFrequency();
	double expectedResult = wave->getAngularFrequency();

	actualEqualsExpected(result, expectedResult);
}
TEST_F(WaveDynamicChildsWithPropertiesSet, WaveLength)
{
	double result = sut->getWaveLength();
	double expectedResult = wave->getLength();

	actualEqualsExpected(result, expectedResult);
}
TEST_F(WaveDynamicChildsWithPropertiesSet, WavePeriod)
{
	double result = sut->getWavePeriod();
	double expectedResult = wave->getPeriod();

	actualEqualsExpected(result, expectedResult);
}
TEST_F(WaveDynamicChildsWithPropertiesSet, WaveHeight)
{
	double result = sut->getWaveHeight();
	double expectedResult = wave->getHeight();

	actualEqualsExpected(result, expectedResult);
}
TEST_F(WaveDynamicChildsWithPropertiesSet, WaterDepth)
{
	double result = sut->getWaterDepth();
	double expectedResult = wave->getWaterDepth();

	actualEqualsExpected(result, expectedResult);
}
