#include "SedimentTransportBinderTest.h"

/////////////////////////////////////// VISITING WORKBOOK /////////////////////////////////////////////
TEST_F(SedimentTransportBinderTest, WhenSedimentTransportBinderVisitsAWorkbookWithSedimentTransportForFirstTime_ShouldAddItToProjects)
{
	WorkbookSubClassAddNodeSpyPtr workbook = WorkbookSubClassAddNodeSpy::getNewInstance();

	sut->visit(workbook);

	EXPECT_TRUE(workbook->wasTriggeredToAddProject());
	EXPECT_THAT(workbook->getAddedNode(), sedimentTransport);
}
TEST_F(SedimentTransportBinderTest, WhenSedimentTransportBinderVisitsAWorkbookWithSedimentTransportForSecondTime_ShouldRemoveItTFromProjects)
{
	WorkbookSubClassAddNodeSpyPtr workbook = WorkbookSubClassAddNodeSpy::getNewInstance();

	sut->visit(workbook);
	sut->visit(workbook);

	EXPECT_TRUE(workbook->wasTriggeredToRemoveProject());
	EXPECT_THAT(workbook->getRemovedNode(), sedimentTransport);
}
