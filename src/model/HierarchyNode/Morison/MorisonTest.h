#ifndef MODEL_MORISONTEST_H
#define MODEL_MORISONTEST_H

#include "gmock/gmock.h"
#include "Morison.h"

#include "model/modelException.h"

#include "model/HierarchyNode/Projects/Morison/MorisonChildTypes.h"
#include "model/HierarchyNode/HierarchyNodeMocks.h"

#include "model/Visitor/VisitorMocks.h"
#include "MorisonVisitorMocks.h"

#include "model/HierarchyNode/Projects/WaveDynamic/WaveDynamicMocks.h"
#include "model/HierarchyNode/BasicElements/Pile/PileMocks.h"
#include "utilities/Math/Math.h"
#include "model/HierarchyNode/PropertyChangedEventArgs.h"
#include "utilities/Event/EventMocks.h"
#include "model/PropertyStrategy/PropertyStrategies/Projects/MorisonStrategy/MorisonProperties.h"

class MorisonTest : public testing::Test
{
protected:
	virtual void SetUp() override
	{
		sut = Morison::getNewInstance();
	}
	MorisonPtr sut;
};

class MorisonWithEventSubClassesForChild : public MorisonTest
{
protected:
	virtual void SetUp() override
	{
		MorisonTest::SetUp();

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

class MorisonChildChangedEventSubClass : public MorisonTest
{
protected:
	virtual void SetUp() override
	{
		MorisonTest::SetUp();

		childEvent = make_shared<EventSubClass<ChildChangedEventArgs> >();
		sut->childChangedEvent = childEvent;
	}
	EventSubClassPtr<ChildChangedEventArgs> childEvent;
};

class MorisonChildsWithPropertiesSet : public MorisonTest
{
protected:
	virtual void SetUp() override
	{
		MorisonTest::SetUp();

		waveDynamic = WaveDynamicSubClassPropertiesStub::getNewInstance();
		pile = PileSubClassPropertiesStub::getNewInstance();

		waveDynamic->setProperties("testWaveDynamic");
		pile->setProperties("testPile");

		sut->setWaveDynamic(waveDynamic);
		sut->setPile(pile);
	}

	virtual void actualEqualsExpected(double actual, double excepted)
	{
		EXPECT_TRUE(utilities::Math::absolut(actual - excepted) <= 10E-4);
	}

	WaveDynamicSubClassPropertiesStubPtr waveDynamic;
	PileSubClassPropertiesStubPtr pile;
};

#endif //MODEL_MORISONTEST_H