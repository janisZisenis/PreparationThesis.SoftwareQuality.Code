#include "HierarchyNodeFactoryImp.h"
#include "model/modelException.h"

#include "model/HierarchyNode/AllNodeIncludes.h"
#include "model/HierarchyNode/AllNodeTypeIncludes.h"


HierarchyNodeFactoryImpPtr HierarchyNodeFactoryImp::getNewInstance() {
    return HierarchyNodeFactoryImpPtr(new HierarchyNodeFactoryImp);
}
HierarchyNodeFactoryImp::~HierarchyNodeFactoryImp() {}
HierarchyNodeFactoryImp::HierarchyNodeFactoryImp() {
    initializeNodeTypes();
}

std::shared_ptr<HierarchyNode> HierarchyNodeFactoryImp::makeHierarchyNode(std::string type) {
    if(type == NodeTypes::coordinateSystem()) return CoordinateSystem::getNewInstance();
    if(type == NodeTypes::morison()) return Morison::getNewInstance();
    if(type == NodeTypes::pile()) return Pile::getNewInstance();
    if(type == NodeTypes::sediment()) return Sediment::getNewInstance();
    if(type == NodeTypes::sedimentTransport()) return SedimentTransport::getNewInstance();
    if(type == NodeTypes::water()) return Water::getNewInstance();
    if(type == NodeTypes::wave()) return Wave::getNewInstance();
    if(type == NodeTypes::waveDynamic()) return WaveDynamic::getNewInstance();

    else throw new InvalidHierarchyNodeType();
}

std::vector<std::string> HierarchyNodeFactoryImp::getNodeTypes() {
    return nodeTypes;
}

void HierarchyNodeFactoryImp::initializeNodeTypes() {
    this->nodeTypes.push_back(NodeTypes::coordinateSystem());
    this->nodeTypes.push_back(NodeTypes::morison());
    this->nodeTypes.push_back(NodeTypes::pile());
    this->nodeTypes.push_back(NodeTypes::sediment());
    this->nodeTypes.push_back(NodeTypes::sedimentTransport());
    this->nodeTypes.push_back(NodeTypes::water());
    this->nodeTypes.push_back(NodeTypes::wave());
    this->nodeTypes.push_back(NodeTypes::waveDynamic());
}


