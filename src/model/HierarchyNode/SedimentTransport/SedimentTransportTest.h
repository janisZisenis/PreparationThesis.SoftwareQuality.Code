#ifndef MODEL_SEDIMENTTRANSPORTTEST_H
#define MODEL_SEDIMENTTRANSPORTTEST_H

#include "gmock/gmock.h"
#include "SedimentTransport.h"

#include "model/modelException.h"

#include "model/Visitor/VisitorMocks.h"
#include "SedimentTransportVisitorMocks.h"

#include "model/HierarchyNode/Projects/SedimentTransport/SedimentTransportChildTypes.h"
#include "model/HierarchyNode/HierarchyNodeMocks.h"

#include "model/HierarchyNode/Projects/WaveDynamic/WaveDynamicMocks.h"
#include "model/HierarchyNode/BasicElements/Sediment/SedimentMocks.h"
#include "utilities/Math/Math.h"
#include "model/HierarchyNode/PropertyChangedEventArgs.h"
#include "utilities/Event/EventMocks.h"
#include "model/PropertyStrategy/PropertyStrategies/Projects/SedimentTransportStrategy/SedimentTransportProperties.h"

class SedimentTransportTest : public testing::Test
{
protected:
	virtual void SetUp() override
	{
		sut = SedimentTransport::getNewInstance();
	}
	SedimentTransportPtr sut;
};

class SedimentTransportWithEventSubClassesForChild : public SedimentTransportTest
{
protected:
	virtual void SetUp() override
	{
		SedimentTransportTest::SetUp();

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

class SedimentTransportChildChangedEventSubClass : public SedimentTransportTest
{
protected:
	virtual void SetUp() override
	{
		SedimentTransportTest::SetUp();

		childEvent = make_shared<EventSubClass<ChildChangedEventArgs> >();
		sut->childChangedEvent = childEvent;
	}
	EventSubClassPtr<ChildChangedEventArgs> childEvent;
};

class SedimentTransportChildsWithPropertiesSet : public SedimentTransportTest
{
protected:
	virtual void SetUp() override
	{
		SedimentTransportTest::SetUp();

		waveDynamic = WaveDynamicSubClassPropertiesStub::getNewInstance();
		sediment = SedimentSubClassPropertiesStub::getNewInstance();

		waveDynamic->setProperties("testWaveDynamic");
		sediment->setProperties("testSediment");

		sut->setWaveDynamic(waveDynamic);
		sut->setSediment(sediment);
	}

	virtual void actualEqualsExpected(double actual, double excepted)
	{
		EXPECT_TRUE(utilities::Math::absolut(actual - excepted) <= 10E-4);
	}

	WaveDynamicSubClassPropertiesStubPtr waveDynamic;
	SedimentSubClassPropertiesStubPtr sediment;
};

#endif //MODEL_SEDIMENTTRANSPORTTEST_H