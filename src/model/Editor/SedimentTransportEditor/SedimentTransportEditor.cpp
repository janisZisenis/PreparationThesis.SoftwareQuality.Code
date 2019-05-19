#include "SedimentTransportEditor.h"

#include <model/HierarchyNode/HierarchyNodeProperties.h>
#include <model/HierarchyNode/SedimentTransport/SedimentTransportProperties.h>
#include "model/HierarchyNode/SedimentTransport/SedimentTransport.h"

SedimentTransportEditorPtr
SedimentTransportEditor::getNewInstance(SedimentTransportPtr node) {
	return SedimentTransportEditorPtr(new SedimentTransportEditor(node));
}
SedimentTransportEditor::~SedimentTransportEditor() {}
SedimentTransportEditor::SedimentTransportEditor(SedimentTransportPtr node) : Editor (), node(node) {}

void SedimentTransportEditor::editProperty(std::string propertyName, std::string propertyValue) {
	if(propertyName == HierarchyNodeProperties::name()) editName(node, propertyValue);
}

std::string SedimentTransportEditor::getPropertyValue(std::string propertyName) {
	if(propertyName == HierarchyNodeProperties::name()) return node->getName();

	throwInvalidPropertyException();
}


