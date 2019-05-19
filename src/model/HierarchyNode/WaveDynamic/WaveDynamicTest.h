#ifndef MODEL_WAVEDYNAMICTEST_H
#define MODEL_WAVEDYNAMICTEST_H

#include "gmock/gmock.h"
#include "WaveDynamic.h"

#include "model/modelException.h"

#include "model/Visitor/VisitorMocks.h"
#include "WaveDynamicChildTypes.h"
#include "WaveDynamicVisitorMocks.h"

#include "model/HierarchyNode/BasicElements/CoordinateSystem/CoordinateSystemMocks.h"
#include "model/HierarchyNode/BasicElements/Water/WaterMocks.h"
#include "model/HierarchyNode/BasicElements/Wave/WaveMocks.h"

#include "utilities/Math/Math.h"
#include "utilities/Event/EventMocks.h"
#include "model/PropertyStrategy/PropertyStrategies/Projects/WaveDynamicStrategy/WaveDynamicProperties.h"
#include "utilities/Event/ObjectMocks.h"

class WaveDynamicTest : public testing::Test
{
protected:
	virtual void SetUp() override
	{
		sut = WaveDynamic::getNewInstance();
	}
	WaveDynamicPtr sut;
};

class WaveDynamicWithEventSubClassesForChild : public WaveDynamicTest
{
protected:
	virtual void SetUp() override
	{
		WaveDynamicTest::SetUp();

		propertyEvent = make_shared<EventSubClass<PropertyChangedEventArgs> >();
		childEvent = make_shared<EventSubClass<ChildChangedEventArgs> >();
	}
	virtual void setEventsTo(HierarchyNodePtr node)
	{
		node->propertyChangedEvent = propertyEvent;
		node->childChangedEvent = childEvent;
	}

	EventSubClassPtr<PropertyChangedEventArgs> propertyEvent;
	EventSubClassPtr<ChildChangedEventArgs> childEvent;
};

class WaveDynamicWithEventSubClasses : public WaveDynamicTest
{
protected:
	virtual void SetUp() override
	{
		WaveDynamicTest::SetUp();

		childEvent = make_shared<EventSubClass<ChildChangedEventArgs> >();
		sut->childChangedEvent = childEvent;

		propertyEvent = make_shared<EventSubClass<PropertyChangedEventArgs> >();
		sut->propertyChangedEvent = propertyEvent;
	}
	EventSubClassPtr<ChildChangedEventArgs> childEvent;
	EventSubClassPtr<PropertyChangedEventArgs> propertyEvent;
};

class WaveDynamicChildsWithPropertiesSet : public WaveDynamicTest
{
protected:
	virtual void SetUp() override
	{
		WaveDynamicTest::SetUp();

		coord = CoordinateSystemSubClassPropertiesStub::getNewInstance();
		water = WaterSubClassPropertiesStub::getNewInstance();
		wave = WaveSubClassPropertiesStub::getNewInstance();

		coord->setProperties("testCoord", 7, 0.5, -5);
		water->setProperties("testWater", 1025, 1.3*10E-6);
		wave->setProperties("testWave", 90, 9.7758, 0.5, 10, 0.0698, 0.6427);

		sut->setCoordinateSystem(coord);
		sut->setWater(water);
		sut->setWave(wave);
	}

	virtual void actualEqualsExpected(double actual, double excepted)
	{
		EXPECT_TRUE(utilities::Math::absolut(actual - excepted) <= 10E-4);
	}

	CoordinateSystemSubClassPropertiesStubPtr coord;
	WaterSubClassPropertiesStubPtr water;
	WaveSubClassPropertiesStubPtr wave;
};

#endif //MODEL_WAVEDYNAMICTEST_H