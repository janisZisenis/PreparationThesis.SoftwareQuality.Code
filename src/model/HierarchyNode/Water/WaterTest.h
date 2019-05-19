#ifndef MODEL_WATERTEST_H
#define MODEL_WATERTEST_H

#include "gmock/gmock.h"
#include "Water.h"

#include "model/modelException.h"

#include "model/HierarchyNode/HierarchyNodeMocks.h"
#include "model/Visitor/VisitorMocks.h"
#include "WaterVisitorMocks.h"
#include "model/HierarchyNode/PropertyChangedEventArgs.h"
#include "utilities/Event/EventMocks.h"
#include "model/PropertyStrategy/PropertyStrategies/BasicElements/WaterStrategy/WaterProperties.h"

class WaterTest : public testing::Test
{
protected:
	virtual void SetUp() override
	{
		sut = Water::getNewInstance();
	}
	WaterPtr sut;
};

class WaterPropertyChangedEventSubClass : public WaterTest
{
protected:
	virtual void SetUp() override
	{
		WaterTest::SetUp();

		evt = make_shared<EventSubClass<PropertyChangedEventArgs> >();
		sut->propertyChangedEvent = evt;
	}
	EventSubClassPtr<PropertyChangedEventArgs> evt;
};

#endif //MODEL_WATERTEST_H