#pragma once
#include "WaveDynamicBinderTest.h"

/////////////////////////////////////// VISITING MORISON /////////////////////////////////////////////
TEST_F(WaveDynamicBinderTest, WhenWaveDynamicBinderVisitsAMorison_ShouldSetTheWaveDynamicToMorison)
{
	MorisonSubClassPtr morison = MorisonSubClass::getNewInstance();

	sut->visit(morison);

	EXPECT_THAT(morison->getWaveDynamic(), waveDynamic);
}
TEST_F(WaveDynamicBinderTest, WhenWaveDynamicBinderVisitsAMorisonWithWaveDynamicForSecondTime_ShouldSetTheOldWaveDynamicToMorison)
{
	MorisonSubClassPtr morison = MorisonSubClass::getNewInstance();
	WaveDynamicSubClassPtr oldWaveDynamic = WaveDynamicSubClass::getNewInstance();
	morison->setWaveDynamic(oldWaveDynamic);

	sut->visit(morison);
	sut->visit(morison);

	EXPECT_THAT(morison->getWaveDynamic(), oldWaveDynamic);
}

/////////////////////////////////////// VISITING SEDIMENTTRANSPORT /////////////////////////////////////////////
TEST_F(WaveDynamicBinderTest, WhenWaveDynamicBinderVisitsASedimentTransportWithWaveDynamicForSecondTime_ShouldSetTheOldWaveDynamicToSedimentTransport)
{
	SedimentTransportSubClassPtr sedimentTransport = SedimentTransportSubClass::getNewInstance();
	WaveDynamicSubClassPtr oldWaveDynamic = WaveDynamicSubClass::getNewInstance();
	sedimentTransport->setWaveDynamic(oldWaveDynamic);

	sut->visit(sedimentTransport);
	sut->visit(sedimentTransport);

	EXPECT_THAT(sedimentTransport->getWaveDynamic(), oldWaveDynamic);
}
TEST_F(WaveDynamicBinderTest, WhenWaveDynamicBinderVisitsASedimentTransport_ShouldSetTheWaveDynamicToSedimentTransport)
{
	SedimentTransportSubClassPtr sedimentTransport = SedimentTransportSubClass::getNewInstance();

	sut->visit(sedimentTransport);

	EXPECT_THAT(sedimentTransport->getWaveDynamic(), waveDynamic);
}

/////////////////////////////////////// VISITING WORKBOOK /////////////////////////////////////////////
TEST_F(WaveDynamicBinderTest, WhenWaveDynamicBinderVisitsAWorkbookWithWaveDynamicForFirstTime_ShouldAddItToProjects)
{
	WorkbookSubClassAddNodeSpyPtr workbook = WorkbookSubClassAddNodeSpy::getNewInstance();

	sut->visit(workbook);

	EXPECT_TRUE(workbook->wasTriggeredToAddProject());
	EXPECT_THAT(workbook->getAddedNode(), waveDynamic);
}
TEST_F(WaveDynamicBinderTest, WhenWaveDynamicBinderVisitsAWorkbookWithWaveDynamicForSecondTime_ShouldRemoveItTFromProjects)
{
	WorkbookSubClassAddNodeSpyPtr workbook = WorkbookSubClassAddNodeSpy::getNewInstance();

	sut->visit(workbook);
	sut->visit(workbook);

	EXPECT_TRUE(workbook->wasTriggeredToRemoveProject());
	EXPECT_THAT(workbook->getRemovedNode(), waveDynamic);
}
