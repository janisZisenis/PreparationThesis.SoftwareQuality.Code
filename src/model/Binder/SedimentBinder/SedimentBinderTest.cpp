#include "SedimentBinderTest.h"

/////////////////////////////////////// VISITING SEDIMENTTRANSPORT /////////////////////////////////////////////
TEST_F(SedimentBinderTest, WhenSedimentBinderVisitsASedimentTransport_ShouldSetTheSedimentToSedimentTransport)
{
	SedimentTransportSubClassPtr sedimentTransport = SedimentTransportSubClass::getNewInstance();

	sut->visit(sedimentTransport);

	EXPECT_THAT(sedimentTransport->getSediment(), sediment);
}
TEST_F(SedimentBinderTest, WhenSedimentBinderVisitsASedimentTransportWithSedimentForSecondTime_ShouldSetTheOldSedimentToSedimentTransport)
{
	SedimentTransportSubClassPtr sedimentTransport = SedimentTransportSubClass::getNewInstance();
	SedimentSubClassPtr oldSediment = SedimentSubClass::getNewInstance();
	sedimentTransport->setSediment(oldSediment);

	sut->visit(sedimentTransport);
	sut->visit(sedimentTransport);

	EXPECT_THAT(sedimentTransport->getSediment(), oldSediment);
}

/////////////////////////////////////// VISITING WORKBOOK /////////////////////////////////////////////
TEST_F(SedimentBinderTest, WhenSedimentBinderVisitsAWorkbookWithSedimentForFirstTime_ShouldAddItToBasicElements)
{
	WorkbookSubClassAddNodeSpyPtr workbook = WorkbookSubClassAddNodeSpy::getNewInstance();

	sut->visit(workbook);

	EXPECT_TRUE(workbook->wasTriggeredToAddBasicElement());
	EXPECT_THAT(workbook->getAddedNode(), sediment);
}
TEST_F(SedimentBinderTest, WhenSedimentBinderVisitsAWorkbookWithSedimentForSecondTime_ShouldRemoveItTFromBasicElements)
{
	WorkbookSubClassAddNodeSpyPtr workbook = WorkbookSubClassAddNodeSpy::getNewInstance();

	sut->visit(workbook);
	sut->visit(workbook);

	EXPECT_TRUE(workbook->wasTriggeredToRemoveBasicElement());
	EXPECT_THAT(workbook->getRemovedNode(), sediment);
}
