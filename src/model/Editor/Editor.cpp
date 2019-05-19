#include "Editor.h"
#include <model/HierarchyNode/HierarchyNode.h>
#include <sstream>
#include <utilities/String/String.h>

Editor::~Editor() {}
Editor::Editor() {}

void Editor::editName(std::shared_ptr<HierarchyNode> node, std::string propertyValue) {
	node->setName(propertyValue);
}

void Editor::throwInvalidPropertyException() {
    throw new InvalidPropertyException();
}

double Editor::convertToDouble(std::string s) {
    try {
        return utilities::String::toDouble(s);
    } catch (InvalidFormatException* e) {
        delete e;
        throw new InvalidPropertyFormatException();
    }
}

const char *InvalidPropertyException::what() const throw() {
    std::ostringstream getNr;
    getNr << "Property is invalid!";
    return getNr.str().c_str();
}

const char *InvalidPropertyFormatException::what() const throw() {
    std::ostringstream getNr;
    getNr << "Can not convert to needed format!";
    return getNr.str().c_str();
}
