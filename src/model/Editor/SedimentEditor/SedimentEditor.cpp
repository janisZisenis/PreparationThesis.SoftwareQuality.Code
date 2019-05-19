#include <utilities/String/String.h>
#include "SedimentEditor.h"

#include <model/HierarchyNode/HierarchyNodeProperties.h>
#include "model/HierarchyNode/Sediment/SedimentProperties.h"
#include "model/HierarchyNode/Sediment/Sediment.h"

SedimentEditorPtr
SedimentEditor::getNewInstance(SedimentPtr node) {
	return SedimentEditorPtr(new SedimentEditor(node));
}
SedimentEditor::~SedimentEditor() {}
SedimentEditor::SedimentEditor(SedimentPtr node) : Editor (), node(node){}

void SedimentEditor::editProperty(std::string propertyName, std::string propertyValue) {
    if(propertyName == HierarchyNodeProperties::name()) editName(node, propertyValue);
	if(propertyName == SedimentProperties::density()) node->setDensity(convertToDouble(propertyValue));
}

std::string SedimentEditor::getPropertyValue(std::string propertyName) {
	if (propertyName == HierarchyNodeProperties::name()) return node->getName();
	if (propertyName == SedimentProperties::density()) return std::to_string(node->getDensity());

	throwInvalidPropertyException();
}


