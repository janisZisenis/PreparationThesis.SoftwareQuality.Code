#pragma once

#include <exception>
#include <iostream>
#include <string>
#include <sstream>

class modelException : public std::exception {
public:
    virtual const char *what() const throw() = 0;
};
