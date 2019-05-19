#ifndef MODEL_HIERARCHYNODETEST_H
#define MODEL_HIERARCHYNODETEST_H

#include "gmock/gmock.h"
#include "HierarchyNodeMocks.h"

#include "model/PropertyStrategy/HierarchyNodeProperties.h"
#include "utilities/Event/EventMocks.h"
#include "PropertyChangedEventArgs.h"
#include "utilities/Event/ObjectMocks.h"

class HierarchyNodeTest : public testing::Test
{
protected:
	virtual void SetUp() override
	{
		sut = HierarchyNodeSubClass::getNewInstance();
	}
	HierarchyNodeSubClassPtr sut;
};

class HierarchyNodeWithEventSubClasses : public HierarchyNodeTest
{
protected:
	virtual void SetUp() override
	{
		HierarchyNodeTest::SetUp();

		childEvent = make_shared<EventSubClass<ChildChangedEventArgs> >();
		sut->childChangedEvent = childEvent;

		propertyEvent = make_shared<EventSubClass<PropertyChangedEventArgs> >();
		sut->propertyChangedEvent = propertyEvent;
	}
	EventSubClassPtr<PropertyChangedEventArgs> propertyEvent;
	EventSubClassPtr<ChildChangedEventArgs> childEvent;
};

#endif //MODEL_HIERARCHYNODETEST_H