#include "WaveBinderTest.h"

/////////////////////////////////////// VISITING WAVEDYNAMIC /////////////////////////////////////////////
TEST_F(WaveBinderTest, WhenWaveBinderVisitsAWaveDynamic_ShouldSetTheWaveToWaveDynamic)
{
	WaveDynamicSubClassPtr waveDynamic = WaveDynamicSubClass::getNewInstance();

	sut->visit(waveDynamic);

	EXPECT_THAT(waveDynamic->getWave(), wave);
}
TEST_F(WaveBinderTest, WhenWaveBinderVisitsAWaveDynamicWithWaveForSecondTime_ShouldSetTheOldWaveToWaveDynamic)
{
	WaveDynamicSubClassPtr waveDynamic = WaveDynamicSubClass::getNewInstance();
	WaveSubClassPtr oldWave = WaveSubClass::getNewInstance();
	waveDynamic->setWave(oldWave);

	sut->visit(waveDynamic);
	sut->visit(waveDynamic);

	EXPECT_THAT(waveDynamic->getWave(), oldWave);
}

/////////////////////////////////////// VISITING WORKBOOK /////////////////////////////////////////////
TEST_F(WaveBinderTest, WhenWaveBinderVisitsAWorkbookWithWaveForFirstTime_ShouldAddItToBasicElements)
{
	WorkbookSubClassAddNodeSpyPtr workbook = WorkbookSubClassAddNodeSpy::getNewInstance();

	sut->visit(workbook);

	EXPECT_TRUE(workbook->wasTriggeredToAddBasicElement());
	EXPECT_THAT(workbook->getAddedNode(), wave);
}
TEST_F(WaveBinderTest, WhenWaveBinderVisitsAWorkbookWithWaveForSecondTime_ShouldRemoveItTFromBasicElements)
{
	WorkbookSubClassAddNodeSpyPtr workbook = WorkbookSubClassAddNodeSpy::getNewInstance();

	sut->visit(workbook);
	sut->visit(workbook);

	EXPECT_TRUE(workbook->wasTriggeredToRemoveBasicElement());
	EXPECT_THAT(workbook->getRemovedNode(), wave);
}