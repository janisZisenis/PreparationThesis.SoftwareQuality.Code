#include <utilities/String/String.h>
#include "PileEditor.h"

#include <model/HierarchyNode/HierarchyNodeProperties.h>
#include <model/HierarchyNode/HierarchyNodeProperties.h>
#include "model/HierarchyNode/Pile/PileProperties.h"
#include "model/HierarchyNode/Pile/Pile.h"

PileEditorPtr
PileEditor::getNewInstance(PilePtr node) {
	return PileEditorPtr(new PileEditor(node));
}
PileEditor::~PileEditor() {}
PileEditor::PileEditor(PilePtr node) : Editor (), node(node) {}

void PileEditor::editProperty(std::string propertyName, std::string propertyValue) {
	if(propertyName == HierarchyNodeProperties::name()) editName(node, propertyValue);
	if(propertyName == PileProperties::diameter()) node->setDiameter(convertToDouble(propertyValue));
}

std::string PileEditor::getPropertyValue(std::string propertyName) {
	if (propertyName == HierarchyNodeProperties::name()) return node->getName();
	if (propertyName == PileProperties::diameter()) return std::to_string(node->getDiameter());

	throwInvalidPropertyException();
}


