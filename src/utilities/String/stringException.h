#ifndef UTILITIES_STRINGEXCEPTION_H
#define UTILITIES_STRINGEXCEPTION_H

#include <exception>
#include <iostream>
#include <string>
#include <sstream>

class stringException : public std::exception {
public:
	virtual const char* what() const throw() = 0;
};

class InvalidFormatException : public stringException
{
	const char* what() const throw()
	{
		std::ostringstream getNr;
		getNr << "The given value has an invalid format!";
		return getNr.str().c_str();
	}
};

#endif //UTILITIES_STRINGEXCEPTION_H