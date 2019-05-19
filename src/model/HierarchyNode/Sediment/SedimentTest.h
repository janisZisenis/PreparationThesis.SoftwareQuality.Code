#ifndef MODEL_SEDIMENTTEST_H
#define MODEL_SEDIMENTTEST_H

#include "gmock/gmock.h"
#include "Sediment.h"

#include "model/modelException.h"

#include "model/HierarchyNode/HierarchyNodeMocks.h"
#include "model/Visitor/VisitorMocks.h"
#include "SedimentVisitorMocks.h"
#include "model/HierarchyNode/PropertyChangedEventArgs.h"
#include "utilities/Event/EventMocks.h"
#include "model/PropertyStrategy/PropertyStrategies/BasicElements/SedimentStrategy/SedimentProperties.h"

class SedimentTest : public testing::Test
{
protected:
	virtual void SetUp() override
	{
		sut = Sediment::getNewInstance();
	}
	SedimentPtr sut;
};

class SedimentPropertyChangedEventSubClass : public SedimentTest
{
protected:
	virtual void SetUp() override
	{
		SedimentTest::SetUp();

		evt = make_shared<EventSubClass<PropertyChangedEventArgs> >();
		sut->propertyChangedEvent = evt;
	}
	EventSubClassPtr<PropertyChangedEventArgs> evt;
};

#endif //MODEL_SEDIMENTTEST_H