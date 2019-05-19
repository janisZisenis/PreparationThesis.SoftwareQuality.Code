#ifndef MODEL_PILETEST_H
#define MODEL_PILETEST_H

#include "gmock/gmock.h"
#include "Pile.h"

#include "model/modelException.h"

#include "model/HierarchyNode/HierarchyNodeMocks.h"
#include "model/Visitor/VisitorMocks.h"
#include "PileVisitorMocks.h"
#include "model/HierarchyNode/PropertyChangedEventArgs.h"
#include "utilities/Event/EventMocks.h"
#include "model/PropertyStrategy/PropertyStrategies/BasicElements/PileStrategy/PileProperties.h"

class PileTest : public testing::Test
{
protected:
	virtual void SetUp() override
	{
		sut = Pile::getNewInstance();
	}
	PilePtr sut;
};

class PilePropertyChangedEventSubClass : public PileTest
{
protected:
	virtual void SetUp() override
	{
		PileTest::SetUp();

		evt = make_shared<EventSubClass<PropertyChangedEventArgs> >();
		sut->propertyChangedEvent = evt;
	}
	EventSubClassPtr<PropertyChangedEventArgs> evt;
};

#endif //MODEL_PILETEST_H