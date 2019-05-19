#ifndef MODELWATERBINDERTEST_H
#define MODELWATERBINDERTEST_H

#include "gmock/gmock.h"
#include "WaterBinder.h"

#include "model/HierarchyNode/BasicElements/Water/WaterMocks.h"

#include "model/HierarchyNode/Projects/WaveDynamic/WaveDynamicMocks.h"
#include "model/HierarchyNode/Workbook/WorkbookMocks.h"

class WaterBinderTest : public testing::Test
{
protected:
	virtual void SetUp() override
	{
		water = WaterSubClass::getNewInstance();
		sut = WaterBinder::getNewInstance(water);
	}
	WaterSubClassPtr water;
	WaterBinderPtr sut;
};

#endif //MODELWATERBINDERTEST_H