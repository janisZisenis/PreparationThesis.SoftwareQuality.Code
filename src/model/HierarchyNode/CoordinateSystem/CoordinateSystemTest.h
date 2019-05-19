#ifndef MODEL_COORDINATESYSTEMTEST_H
#define MODEL_COORDINATESYSTEMTEST_H

#include "gmock/gmock.h"
#include "CoordinateSystem.h"

#include "model/modelException.h"

#include "model/HierarchyNode/HierarchyNodeMocks.h"
#include "model/Visitor/VisitorMocks.h"
#include "CoordinateSystemVisitorMocks.h"
#include "model/HierarchyNode/PropertyChangedEventArgs.h"
#include "utilities/Event/EventMocks.h"
#include "model/PropertyStrategy/PropertyStrategies/BasicElements/CoordinateSystemStrategy/CoordinateSystemProperties.h"

class CoordinateSystemTest : public testing::Test
{
protected:
	virtual void SetUp() override
	{
		sut = CoordinateSystem::getNewInstance();
	}
	CoordinateSystemPtr sut;
};

class CoordinateSystemPropertyChangedEventSubClass : public CoordinateSystemTest
{
protected:
	virtual void SetUp() override
	{
		CoordinateSystemTest::SetUp();

		evt = make_shared<EventSubClass<PropertyChangedEventArgs> >();
		sut->propertyChangedEvent = evt;
	}
	EventSubClassPtr<PropertyChangedEventArgs> evt;
};

#endif //MODEL_COORDINATESYSTEMTEST_H