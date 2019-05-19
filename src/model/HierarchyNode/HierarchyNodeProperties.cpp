#include "HierarchyNodeProperties.h"


model_EXPORT const std::string HierarchyNodeProperties::name() {
	return "Name";
}

model_EXPORT const std::string HierarchyNodeProperties::type() {
	return "Type";
}

model_EXPORT const std::string HierarchyNodeProperties::emptyChild() {
	return "Empty";
}

model_EXPORT const std::string HierarchyNodeProperties::boundChild(std::string type) {
	return type;
}
