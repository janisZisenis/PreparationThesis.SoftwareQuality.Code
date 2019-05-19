#include "StringTest.h"

///////////////////////////////////////// TRIM STRINGS /////////////////////////////////////////
TEST_F(StringTest, WhenStringIsTrimmedShould_EraseTheSpacesOnTheSides)
{
	EXPECT_THAT(utilities::String::trim("trim"), testing::StrEq("trim"));
	EXPECT_THAT(utilities::String::trim(" trim"), testing::StrEq("trim"));
	EXPECT_THAT(utilities::String::trim("trim "), testing::StrEq("trim"));

	EXPECT_THAT(utilities::String::trim("      "), testing::StrEq(""));
	EXPECT_THAT(utilities::String::trim(""), testing::StrEq(""));
}

///////////////////////////////////////// CONVERT TO DOUBLE /////////////////////////////////////////
TEST_F(StringTest, WhenToDoublePerformedWithValidFormat_ShouldReturnTheStringAsDouble)
{
	expectConvertedStringEqualsDouble("5.123", 5.123);
	expectConvertedStringEqualsDouble("0.751", 0.751);
	expectConvertedStringEqualsDouble("00.14", 0.14);
	expectConvertedStringEqualsDouble(".14", 0.14);
	expectConvertedStringEqualsDouble("", 0.0);
}
TEST_F(StringTest, WhenToDoublePerformedWithInvalidFormat_ShouldThrowInvalidFormatException)
{
	asserThrowFormatException("invalidFormat1234");
	asserThrowFormatException("!\�$%&/()=?``�^");
	asserThrowFormatException("1,0");
	asserThrowFormatException("1,0,");
	asserThrowFormatException("1..0");
	asserThrowFormatException("1.0.");
	asserThrowFormatException(".1.0");
	asserThrowFormatException("..10.");
}