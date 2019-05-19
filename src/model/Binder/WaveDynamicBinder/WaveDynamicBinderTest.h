#ifndef MODEL_WAVEDYNAMICBINDERTEST_H
#define MODEL_WAVEDYNAMICBINDERTEST_H

#include "gmock/gmock.h"
#include "WaveDynamicBinder.h"

#include "model/HierarchyNode/Projects/WaveDynamic/WaveDynamicMocks.h"

#include "model/HierarchyNode/Projects/Morison/MorisonMocks.h"
#include "model/HierarchyNode/Projects/SedimentTransport/SedimentTransportMocks.h"
#include "model/HierarchyNode/Workbook/WorkbookMocks.h"

class WaveDynamicBinderTest : public testing::Test
{
protected:
	virtual void SetUp() override
	{
		waveDynamic = WaveDynamicSubClass::getNewInstance();
		sut = WaveDynamicBinder::getNewInstance(waveDynamic);
	}
	WaveDynamicSubClassPtr waveDynamic;
	WaveDynamicBinderPtr sut;
};

#endif //MODEL_WAVEDYNAMICBINDERTEST_H