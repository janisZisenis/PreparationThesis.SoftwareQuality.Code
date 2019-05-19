#ifndef MODEL_WAVETEST_H
#define MODEL_WAVETEST_H

#include "gmock/gmock.h"
#include "Wave.h"

#include "model/modelException.h"

#include "model/HierarchyNode/HierarchyNodeMocks.h"
#include "model/Visitor/VisitorMocks.h"
#include "WaveVisitorMocks.h"
#include "utilities/Math/Math.h"
#include "model/HierarchyNode/PropertyChangedEventArgs.h"
#include "utilities/Event/EventMocks.h"
#include "model/PropertyStrategy/PropertyStrategies/BasicElements/WaveStrategy/WaveProperties.h"

class WaveTest : public testing::Test
{
protected:
	virtual void SetUp() override
	{
		sut = Wave::getNewInstance();
	}
	WavePtr sut;
};

class WavePropertyChangedEventSubClass : public WaveTest
{
protected:
	virtual void SetUp() override
	{
		WaveTest::SetUp();

		evt = make_shared<EventSubClass<PropertyChangedEventArgs> >();
		sut->propertyChangedEvent = evt;
	}
	EventSubClassPtr<PropertyChangedEventArgs> evt;
};

class WaveWithPropertiesSet : public WaveTest
{
protected:
	virtual void SetUp() override
	{
		WaveTest::SetUp();

		sut->setLength(90);
		sut->setPeriod(9.7758);
		sut->setHeight(0.5);
		sut->setWaterDepth(10);
	}
	virtual void actualEqualsExpected(double actual, double excepted)
	{
		EXPECT_TRUE(utilities::Math::absolut(actual - excepted) <= 10E-4);
	}
};

#endif //MODEL_WAVETEST_H