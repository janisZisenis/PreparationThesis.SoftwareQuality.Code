#include "Math.h"

#include <cmath>

#define _USE_MATH_DEFINES
#include <math.h>

double utilities::Math::pi()
{
	return M_PI;
}

double utilities::Math::absolut(double value)
{
	return std::abs(value);
}

double utilities::Math::cos(double value)
{
	return std::cos(value);
}

double utilities::Math::cosh(double value)
{
	return std::cosh(value);
}

double utilities::Math::sinh(double value)
{
	return std::sinh(value);
}

double utilities::Math::tanh(double value)
{
	return sinh(value) / cosh(value);
}
