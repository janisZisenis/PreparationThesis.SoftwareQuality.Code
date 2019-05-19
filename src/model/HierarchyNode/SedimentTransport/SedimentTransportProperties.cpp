#include "SedimentTransportProperties.h"
#include "model/HierarchyNode/HierarchyNodeProperties.h"
#include "model/HierarchyNode/SedimentTransport/SedimentTransportChildTypes.h"

model_EXPORT const std::string SedimentTransportProperties::waveDynamic() {
    return HierarchyNodeProperties::boundChild(NodeTypes::waveDynamic());
}

model_EXPORT const std::string SedimentTransportProperties::sediment() {
    return HierarchyNodeProperties::boundChild(NodeTypes::sediment());
}

model_EXPORT const std::string SedimentTransportProperties::water() {
    return HierarchyNodeProperties::boundChild(NodeTypes::water());
}