#ifndef UTILITIES_STRINGTEST_H
#define UTILITIES_STRINGTEST_H

#include "gmock/gmock.h"
#include "String.h"


#include "stringException.h"

#include "utilities/Math/Math.h"


class StringTest : public testing::Test
{
protected:
	virtual void SetUp() override {}

	virtual void expectConvertedStringEqualsDouble(std::string valid, double second)
	{
		double converted = utilities::String::toDouble(valid);
		double delta = utilities::Math::absolut(second - converted);

		EXPECT_TRUE(delta <= 10E-6);
	}
	virtual void asserThrowFormatException(std::string invalid)
	{
		ASSERT_THROW(utilities::String::toDouble(invalid), InvalidFormatException*);
	}
};

#endif //UTILITIES_STRINGTEST_H