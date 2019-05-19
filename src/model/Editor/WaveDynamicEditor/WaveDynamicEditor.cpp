#include "WaveDynamicEditor.h"

#include <model/HierarchyNode/HierarchyNodeProperties.h>
#include "model/HierarchyNode/WaveDynamic/WaveDynamicProperties.h"
#include "model/HierarchyNode/WaveDynamic/WaveDynamic.h"

WaveDynamicEditorPtr
WaveDynamicEditor::getNewInstance(WaveDynamicPtr node) {
	return WaveDynamicEditorPtr(new WaveDynamicEditor(node));
}
WaveDynamicEditor::~WaveDynamicEditor() {}
WaveDynamicEditor::WaveDynamicEditor(WaveDynamicPtr node) : Editor (), node(node) {}

void WaveDynamicEditor::editProperty(std::string propertyName, std::string propertyValue) {
	if(propertyName == HierarchyNodeProperties::name()) editName(node, propertyValue);
}

std::string WaveDynamicEditor::getPropertyValue(std::string propertyName) {
	if(propertyName == HierarchyNodeProperties::name()) return node->getName();

	throwInvalidPropertyException();
}