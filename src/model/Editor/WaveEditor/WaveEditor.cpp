#include "WaveEditor.h"
#include <utilities/String/String.h>
#include <model/HierarchyNode/HierarchyNodeProperties.h>
#include "model/HierarchyNode/Wave/WaveProperties.h"
#include "model/HierarchyNode/Wave/Wave.h"

WaveEditorPtr
WaveEditor::getNewInstance(WavePtr node) {
	return WaveEditorPtr(new WaveEditor(node));
}
WaveEditor::~WaveEditor() {}
WaveEditor::WaveEditor(WavePtr node) : Editor (), node(node) {}

void WaveEditor::editProperty(std::string propertyName, std::string propertyValue) {
    if(propertyName == HierarchyNodeProperties::name()) editName(node, propertyValue);
	if(propertyName == WaveProperties::waterDepth()) node->setWaterDepth(convertToDouble(propertyValue));
	if(propertyName == WaveProperties::waveHeight()) node->setHeight(convertToDouble(propertyValue));
	if(propertyName == WaveProperties::wavePeriod()) node->setPeriod(convertToDouble(propertyValue));
	if(propertyName == WaveProperties::waveLength()) node->setLength(convertToDouble(propertyValue));
}

std::string WaveEditor::getPropertyValue(std::string propertyName) {
	if (propertyName == HierarchyNodeProperties::name()) return node->getName();
	if (propertyName == WaveProperties::waterDepth()) return std::to_string(node->getWaterDepth());
	if (propertyName == WaveProperties::waveHeight()) return std::to_string(node->getHeight());
	if (propertyName == WaveProperties::wavePeriod()) return std::to_string(node->getPeriod());
	if (propertyName == WaveProperties::waveLength()) return std::to_string(node->getLength());

	throwInvalidPropertyException();
}

