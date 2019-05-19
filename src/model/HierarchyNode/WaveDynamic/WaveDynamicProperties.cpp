#include "WaveDynamicProperties.h"
#include "model/HierarchyNode/WaveDynamic/WaveDynamicChildTypes.h"
#include "model/HierarchyNode/HierarchyNodeProperties.h"

model_EXPORT const std::string WaveDynamicProperties::coordinateSystem() {
    return HierarchyNodeProperties::boundChild(NodeTypes::coordinateSystem());
}

model_EXPORT const std::string WaveDynamicProperties::wave() {
    return HierarchyNodeProperties::boundChild(NodeTypes::wave());
}
