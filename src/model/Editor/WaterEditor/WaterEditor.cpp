#include <utilities/String/String.h>
#include "WaterEditor.h"

#include <model/HierarchyNode/HierarchyNodeProperties.h>
#include "model/HierarchyNode/Water/WaterProperties.h"
#include "model/HierarchyNode/Water/Water.h"

WaterEditorPtr
WaterEditor::getNewInstance(WaterPtr node) {
	return WaterEditorPtr(new WaterEditor(node));
}
WaterEditor::~WaterEditor() {}
WaterEditor::WaterEditor(WaterPtr node) : Editor (), node(node) {}

void WaterEditor::editProperty(std::string propertyName, std::string propertyValue) {
    if(propertyName == HierarchyNodeProperties::name()) editName(node, propertyValue);
	if(propertyName == WaterProperties::density()) node->setDensity(convertToDouble(propertyValue));
	if(propertyName == WaterProperties::viscosity()) node->setViscosity(convertToDouble(propertyValue));
}

std::string WaterEditor::getPropertyValue(std::string propertyName) {
	if (propertyName == HierarchyNodeProperties::name()) return node->getName();
	if (propertyName == WaterProperties::density()) return std::to_string(node->getDensity());
	if (propertyName == WaterProperties::viscosity()) return std::to_string(node->getViscosity());

	throwInvalidPropertyException();
}


