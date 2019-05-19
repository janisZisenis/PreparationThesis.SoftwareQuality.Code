#ifndef MODEL_PILEBINDERTEST_H
#define MODEL_PILEBINDERTEST_H

#include "gmock/gmock.h"
#include "PileBinder.h"

#include "model/HierarchyNode/BasicElements/Pile/PileMocks.h"

#include "model/HierarchyNode/Projects/Morison/MorisonMocks.h"
#include "model/HierarchyNode/Workbook/WorkbookMocks.h"

class PileBinderTest : public testing::Test
{
protected:
	virtual void SetUp() override
	{
		pile = PileSubClass::getNewInstance();
		sut = PileBinder::getNewInstance(pile);
	}
	PileSubClassPtr pile;
	PileBinderPtr sut;
};

#endif //MODEL_PILEBINDERTEST_H