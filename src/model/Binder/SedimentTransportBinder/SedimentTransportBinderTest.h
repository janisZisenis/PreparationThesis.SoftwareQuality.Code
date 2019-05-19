#ifndef MODEL_SEDIMENTTRANSPORTBINDERTEST_H
#define MODEL_SEDIMENTTRANSPORTBINDERTEST_H

#include "gmock/gmock.h"
#include "SedimentTransportBinder.h"

#include "model/HierarchyNode/Projects/SedimentTransport/SedimentTransportMocks.h"

#include "model/HierarchyNode/Workbook/WorkbookMocks.h"

class SedimentTransportBinderTest : public testing::Test
{
protected:
	virtual void SetUp() override
	{
		sedimentTransport = SedimentTransportSubClass::getNewInstance();
		sut = SedimentTransportBinder::getNewInstance(sedimentTransport);
	}
	SedimentTransportSubClassPtr sedimentTransport;
	SedimentTransportBinderPtr sut;
};

#endif //MODEL_SEDIMENTTRANSPORTBINDERTEST_H