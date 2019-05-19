#ifndef MODEL_COORDINATESYSTEMBINDERTEST_H
#define MODEL_COORDINATESYSTEMBINDERTEST_H

#include "gmock/gmock.h"
#include "CoordinateSystemBinder.h"

#include "model/HierarchyNode/BasicElements/CoordinateSystem/CoordinateSystemMocks.h"

#include "model/HierarchyNode/Projects/WaveDynamic/WaveDynamicMocks.h"
#include "model/HierarchyNode/Workbook/WorkbookMocks.h"

class CoordinateSystemBinderTest : public testing::Test
{
protected:
	virtual void SetUp() override
	{
		coordinateSystem = CoordinateSystemSubClass::getNewInstance();
		sut = CoordinateSystemBinder::getNewInstance(coordinateSystem);
	}
	CoordinateSystemSubClassPtr coordinateSystem;
	CoordinateSystemBinderPtr sut;
};

#endif //MODEL_COORDINATESYSTEMBINDERTEST_H