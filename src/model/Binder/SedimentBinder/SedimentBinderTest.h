#ifndef MODEL_SEDIMENTBINDERTEST_H
#define MODEL_SEDIMENTBINDERTEST_H

#include "gmock/gmock.h"
#include "SedimentBinder.h"

#include "model/HierarchyNode/BasicElements/Sediment/SedimentMocks.h"

#include "model/HierarchyNode/Projects/SedimentTransport/SedimentTransportMocks.h"
#include "model/HierarchyNode/Workbook/WorkbookMocks.h"

class SedimentBinderTest : public testing::Test
{
protected:
	virtual void SetUp() override
	{
		sediment = SedimentSubClass::getNewInstance();
		sut = SedimentBinder::getNewInstance(sediment);
	}
	SedimentSubClassPtr sediment;
	SedimentBinderPtr sut;
};

#endif //MODEL_SEDIMENTBINDERTEST_H