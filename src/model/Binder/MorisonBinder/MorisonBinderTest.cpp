#pragma once
#include "MorisonBinderTest.h"

/////////////////////////////////////// VISITING WORKBOOK /////////////////////////////////////////////
TEST_F(MorisonBinderTest, WhenMorisonBinderVisitsAWorkbookWithMorisonForFirstTime_ShouldAddItToProjects)
{
	WorkbookSubClassAddNodeSpyPtr workbook = WorkbookSubClassAddNodeSpy::getNewInstance();

	sut->visit(workbook);

	EXPECT_TRUE(workbook->wasTriggeredToAddProject());
	EXPECT_THAT(workbook->getAddedNode(), morison);
}
TEST_F(MorisonBinderTest, WhenMorisonBinderVisitsAWorkbookWithMorisonForSecondTime_ShouldRemoveItTFromProjects)
{
	WorkbookSubClassAddNodeSpyPtr workbook = WorkbookSubClassAddNodeSpy::getNewInstance();

	sut->visit(workbook);
	sut->visit(workbook);

	EXPECT_TRUE(workbook->wasTriggeredToRemoveProject());
	EXPECT_THAT(workbook->getRemovedNode(), morison);
}
