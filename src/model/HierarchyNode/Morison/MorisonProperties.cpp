#include "MorisonProperties.h"
#include <model/HierarchyNode/HierarchyNodeProperties.h>
#include <model/HierarchyNode/Morison/MorisonChildTypes.h>

model_EXPORT const std::string MorisonProperties::waveDynamic() {
    return HierarchyNodeProperties::boundChild(NodeTypes::waveDynamic());
}

model_EXPORT const std::string MorisonProperties::pile() {
    return HierarchyNodeProperties::boundChild(NodeTypes::pile());
}

model_EXPORT const std::string MorisonProperties::water() {
    return HierarchyNodeProperties::boundChild(NodeTypes::water());
}

