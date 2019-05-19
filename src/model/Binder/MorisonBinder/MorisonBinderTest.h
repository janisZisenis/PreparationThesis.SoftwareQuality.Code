#ifndef MODEL_MORISONBINDERTEST_H
#define MODEL_MORISONBINDERTEST_H

#include "gmock/gmock.h"
#include "MorisonBinder.h"

#include "model/HierarchyNode/Projects/Morison/MorisonMocks.h"

#include "model/HierarchyNode/Workbook/WorkbookMocks.h"

class MorisonBinderTest : public testing::Test
{
protected:
	virtual void SetUp() override
	{
		morison = MorisonSubClass::getNewInstance();
		sut = MorisonBinder::getNewInstance(morison);
	}
	MorisonSubClassPtr morison;
	MorisonBinderPtr sut;
};

#endif //MODEL_MORISONBINDERTEST_H