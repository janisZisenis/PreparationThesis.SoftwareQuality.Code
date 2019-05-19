#ifndef UTILITIES_STRING_H
#define UTILITIES_STRING_H

#include <utilities/utilities_Export.h>
#include <string>

#include "stringException.h"

namespace utilities {

	class utilities_EXPORT String {
		public:
			static std::string trim(std::string trim);
		private:
			static bool containsOnlySpacesOrEmpty(std::string str);
			static std::string trimLeft(std::string trimLeft);
			static std::string trimRight(std::string trimRight);

		public:
			static double toDouble(std::string dstring);
		private:
			static bool containsComma(std::string dstring);
		  	static bool containsMoreThanOnePoint(std::string dstring);
		 	static double tryConvertToDouble(std::string dstring);
	};

}

#endif //UTILITIES_STRING_H