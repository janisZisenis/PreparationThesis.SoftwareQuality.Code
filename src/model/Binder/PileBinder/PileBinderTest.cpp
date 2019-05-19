#include "PileBinderTest.h"

/////////////////////////////////////// VISITING WAVEDYNAMIC /////////////////////////////////////////////
TEST_F(PileBinderTest, WhenPileBinderVisitsAWaveDynamic_ShouldSetThePileToWaveDynamic)
{
	MorisonSubClassPtr morison = MorisonSubClass::getNewInstance();

	sut->visit(morison);

	EXPECT_THAT(morison->getPile(), pile);
}
TEST_F(PileBinderTest, WhenPileBinderVisitsAWaveDynamicWithPileForSecondTime_ShouldSetTheOldPileToWaveDynamic)
{
	MorisonSubClassPtr morison = MorisonSubClass::getNewInstance();
	PileSubClassPtr oldPile = PileSubClass::getNewInstance();
	morison->setPile(oldPile);

	sut->visit(morison);
	sut->visit(morison);

	EXPECT_THAT(morison->getPile(), oldPile);
}

/////////////////////////////////////// VISITING WORKBOOK /////////////////////////////////////////////
TEST_F(PileBinderTest, WhenPileBinderVisitsAWorkbookWithPileForFirstTime_ShouldAddItToBasicElements)
{
	WorkbookSubClassAddNodeSpyPtr workbook = WorkbookSubClassAddNodeSpy::getNewInstance();

	sut->visit(workbook);

	EXPECT_TRUE(workbook->wasTriggeredToAddBasicElement());
	EXPECT_THAT(workbook->getAddedNode(), pile);
}
TEST_F(PileBinderTest, WhenPileBinderVisitsAWorkbookWithPileForSecondTime_ShouldRemoveItTFromBasicElements)
{
	WorkbookSubClassAddNodeSpyPtr workbook = WorkbookSubClassAddNodeSpy::getNewInstance();

	sut->visit(workbook);
	sut->visit(workbook);

	EXPECT_TRUE(workbook->wasTriggeredToRemoveBasicElement());
	EXPECT_THAT(workbook->getRemovedNode(), pile);
}