#include "Command.h"
#include <sstream>

const char *CommandException::what() const throw() {
    std::ostringstream getNr;
    getNr << "Command threw Exception!";
    return getNr.str().c_str();
}