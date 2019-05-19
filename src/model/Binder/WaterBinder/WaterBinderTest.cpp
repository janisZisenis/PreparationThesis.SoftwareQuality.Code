#include "WaterBinderTest.h"

/////////////////////////////////////// VISITING WAVEDYNAMIC /////////////////////////////////////////////
TEST_F(WaterBinderTest, WhenWaterBinderVisitsAWaveDynamic_ShouldSetTheWaterToWaveDynamic)
{
	WaveDynamicSubClassPtr waveDynamic = WaveDynamicSubClass::getNewInstance();

	sut->visit(waveDynamic);

	EXPECT_THAT(waveDynamic->getWater(), water);
}
TEST_F(WaterBinderTest, WhenWaterBinderVisitsAWaveDynamicWithWaterForSecondTime_ShouldSetTheOldWaterToWaveDynamic)
{
	WaveDynamicSubClassPtr waveDynamic = WaveDynamicSubClass::getNewInstance();
	WaterSubClassPtr oldWater = WaterSubClass::getNewInstance();
	waveDynamic->setWater(oldWater);

	sut->visit(waveDynamic);
	sut->visit(waveDynamic);

	EXPECT_THAT(waveDynamic->getWater(), oldWater);
}

/////////////////////////////////////// VISITING WORKBOOK /////////////////////////////////////////////
TEST_F(WaterBinderTest, WhenWaterBinderVisitsAWorkbookWithWaterForFirstTime_ShouldAddItToBasicElements)
{
	WorkbookSubClassAddNodeSpyPtr workbook = WorkbookSubClassAddNodeSpy::getNewInstance();

	sut->visit(workbook);

	EXPECT_TRUE(workbook->wasTriggeredToAddBasicElement());
	EXPECT_THAT(workbook->getAddedNode(), water);
}
TEST_F(WaterBinderTest, WhenWaterBinderVisitsAWorkbookWithWaterForSecondTime_ShouldRemoveItTFromBasicElements)
{
	WorkbookSubClassAddNodeSpyPtr workbook = WorkbookSubClassAddNodeSpy::getNewInstance();

	sut->visit(workbook);
	sut->visit(workbook);

	EXPECT_TRUE(workbook->wasTriggeredToRemoveBasicElement());
	EXPECT_THAT(workbook->getRemovedNode(), water);
}