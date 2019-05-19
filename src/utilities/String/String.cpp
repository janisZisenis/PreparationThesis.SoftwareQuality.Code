#include "String.h"

#include "stringException.h"

std::string utilities::String::trim(std::string trim)
{
	if (containsOnlySpacesOrEmpty(trim)) return "";

	return trimLeft(trimRight(trim));
}
bool utilities::String::containsOnlySpacesOrEmpty(std::string str)
{
	for (int i = 0; i < str.size(); i++)
		if (str[i] != ' ')
			return false;
	
	return true;
}
std::string utilities::String::trimLeft(std::string trimLeft)
{
	std::string::size_type lastChar = trimLeft.find_last_not_of(' ');
	return trimLeft.substr(0, lastChar + 1);
}
std::string utilities::String::trimRight(std::string trimRight)
{
	std::string::size_type firstChar = trimRight.find_first_not_of(' ');
	return trimRight.substr(firstChar, trimRight.size() - firstChar);
}

double utilities::String::toDouble(std::string dstring)
{
	if (containsOnlySpacesOrEmpty(dstring)) return 0;
	if (containsComma(dstring) || containsMoreThanOnePoint(dstring)) throw new InvalidFormatException();

	return tryConvertToDouble(dstring);
}
bool utilities::String::containsComma(std::string dstring)
{
	for (int i = 0; i < dstring.size(); i++)
		if (dstring[i] == ',')
			return true;
	return false;
}
bool utilities::String::containsMoreThanOnePoint(std::string dstring)
{
	int numberOfPoints = 0;
	for (int i = 0; i < dstring.size(); i++)
		if (dstring[i] == '.')
			numberOfPoints++;

	if (numberOfPoints > 1) return true;
	return false;
}
double utilities::String::tryConvertToDouble(std::string dstring)
{
	try
	{
		return std::stod(dstring);
	}
	catch (std::invalid_argument e)
	{
		throw new InvalidFormatException();
	}
}