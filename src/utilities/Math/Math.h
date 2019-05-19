#ifndef UTILITIES_MATH_H
#define UTILITIES_MATH_H

#include <utilities/utilities_Export.h>

namespace utilities {
    class utilities_EXPORT Math {
    public:
        static double pi();
        static double absolut(double value);
        static double cos(double value);
        static double cosh(double value);
        static double sinh(double value);
        static double tanh(double value);
    };
}

#endif //UTILITIES_MATH_H