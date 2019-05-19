#include "CoordinateSystemEditor.h"
#include <utilities/String/String.h>

#include "model/HierarchyNode/HierarchyNodeProperties.h"
#include "model/HierarchyNode/CoordinateSystem/CoordinateSystemProperties.h"
#include "model/HierarchyNode/CoordinateSystem/CoordinateSystem.h"

CoordinateSystemEditorPtr
CoordinateSystemEditor::getNewInstance(CoordinateSystemPtr node) {
    return CoordinateSystemEditorPtr(new CoordinateSystemEditor(node));
}
CoordinateSystemEditor::~CoordinateSystemEditor() {}
CoordinateSystemEditor::CoordinateSystemEditor(CoordinateSystemPtr node) : Editor (), node(node) {}

void CoordinateSystemEditor::editProperty(std::string propertyName, std::string propertyValue) {
    if(propertyName == HierarchyNodeProperties::name()) editName(node, propertyValue);
    if(propertyName == CoordinateSystemProperties::x()) node->setX(convertToDouble(propertyValue));
    if(propertyName == CoordinateSystemProperties::t()) node->setT(convertToDouble(propertyValue));
    if(propertyName == CoordinateSystemProperties::z()) node->setZ(convertToDouble(propertyValue));
}

std::string CoordinateSystemEditor::getPropertyValue(std::string propertyName) {
    if (propertyName == HierarchyNodeProperties::name()) return node->getName();
    if (propertyName == CoordinateSystemProperties::x()) return std::to_string(node->getX());
    if (propertyName == CoordinateSystemProperties::t()) return std::to_string(node->getT());
    if (propertyName == CoordinateSystemProperties::z()) return std::to_string(node->getZ());

    throwInvalidPropertyException();
}
