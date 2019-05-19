#include "CoordinateSystemBinderTest.h"

/////////////////////////////////////// VISITING WAVEDYNAMIC /////////////////////////////////////////////
TEST_F(CoordinateSystemBinderTest, WhenCoordinateSystemBinderVsiitsAWaveDynamic_ShouldSetTheCoordinateSystemToWaveDynamic)
{
	WaveDynamicSubClassPtr waveDynamic = WaveDynamicSubClass::getNewInstance();

	sut->visit(waveDynamic);

	EXPECT_THAT(waveDynamic->getCoordinateSystem(), coordinateSystem);
}
TEST_F(CoordinateSystemBinderTest, WhenCoordinateSystemBinderVisitsAWaveDynamicWithCoordinateSystemForSecondTime_ShouldSetTheOldCoordinateSystemToWaveDynamic)
{
	WaveDynamicSubClassPtr waveDynamic = WaveDynamicSubClass::getNewInstance();
	CoordinateSystemSubClassPtr oldCoordinateSystem = CoordinateSystemSubClass::getNewInstance();
	waveDynamic->setCoordinateSystem(oldCoordinateSystem);

	sut->visit(waveDynamic);
	sut->visit(waveDynamic);

	EXPECT_THAT(waveDynamic->getCoordinateSystem(), oldCoordinateSystem);
}

/////////////////////////////////////// VISITING WORKBOOK /////////////////////////////////////////////
TEST_F(CoordinateSystemBinderTest, WhenCoordinateSystemBinderVisitsAWorkbookWithCoordinateSystemForFirstTime_ShouldAddItToBasicElements)
{
	WorkbookSubClassAddNodeSpyPtr workbook = WorkbookSubClassAddNodeSpy::getNewInstance();

	sut->visit(workbook);

	EXPECT_TRUE(workbook->wasTriggeredToAddBasicElement());
	EXPECT_THAT(workbook->getAddedNode(), coordinateSystem);
}
TEST_F(CoordinateSystemBinderTest, WhenCoordinateSystemBinderVisitsAWorkbookWithCoordinateSystemForSecondTime_ShouldRemoveItTFromBasicElements)
{
	WorkbookSubClassAddNodeSpyPtr workbook = WorkbookSubClassAddNodeSpy::getNewInstance();

	sut->visit(workbook);
	sut->visit(workbook);

	EXPECT_TRUE(workbook->wasTriggeredToRemoveBasicElement());
	EXPECT_THAT(workbook->getRemovedNode(), coordinateSystem);
}