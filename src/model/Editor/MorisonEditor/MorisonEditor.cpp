#include "MorisonEditor.h"

#include "model/HierarchyNode/HierarchyNodeProperties.h"
#include "model/HierarchyNode/Morison/MorisonProperties.h"
#include "model/HierarchyNode/Morison/Morison.h"

MorisonEditorPtr MorisonEditor::getNewInstance(MorisonPtr node) {
    return MorisonEditorPtr(new MorisonEditor(node));
}
MorisonEditor::~MorisonEditor() {}
MorisonEditor::MorisonEditor(MorisonPtr node) : Editor(), node(node) {}

void MorisonEditor::editProperty(std::string propertyName, std::string propertyValue) {
    if(propertyName == HierarchyNodeProperties::name()) editName(node, propertyValue);
}

std::string MorisonEditor::getPropertyValue(std::string propertyName) {
    if(propertyName == HierarchyNodeProperties::name()) return node->getName();

    throwInvalidPropertyException();
}