#include "HierarchyNode.h"
#include <model/modelException.h>
#include <utilities/Visitor/Visitor.h>
#include <model/Editor/Editor.h>

HierarchyNode::~HierarchyNode() {}
HierarchyNode::HierarchyNode(std::string name, std::string type) : Object(), name(name), type(type) {}

std::string HierarchyNode::getName() const {
    return this->name;
}

std::string HierarchyNode::getType() const {
    return this->type;
}

void HierarchyNode::setName(std::string name) {
    this->name = name;
    nodeChanged(sharedFromThis());
}

HierarchyNodePtr HierarchyNode::sharedFromThis() {
    HierarchyNodePtr me = std::dynamic_pointer_cast<HierarchyNode>(this->shared_from_this());
    if (!me) throw new SharedFromThisException();
    return me;
}

void HierarchyNode::initializeName(int timesInstantiated) {
    if(timesInstantiated > 0)
        this->name += " (" + std::to_string(timesInstantiated) + ")";
}

bool HierarchyNode::canBind(HierarchyNodePtr node) {
    return false;
}

VisitorPtr HierarchyNode::makeBinder() {
    throw new NoBinderException();
}

EditorPtr HierarchyNode::makeEditor() {
    return nullptr;
}

void HierarchyNode::accept(VisitorPtr visitor) {
    throwVisitorCastException();
}

void HierarchyNode::onNodeChanged(const std::shared_ptr<HierarchyNode> changed) {
    nodeChanged(sharedFromThis());
}

void HierarchyNode::connectToNode(HierarchyNodePtr node) {
    if(!node) return;

    node->nodeChanged.connect(boost::bind(&HierarchyNode::onNodeChanged, this, _1));
}

void HierarchyNode::disconnectFromNode(HierarchyNodePtr node) {
    if (!node) return;

    node->childInserted.disconnect(boost::bind(&HierarchyNode::onNodeChanged, this, _1));
}

const char* NoBinderException::what() const throw() {
    std::ostringstream getNr;
    getNr << "No binder for this node type!";
    return getNr.str().c_str();
}