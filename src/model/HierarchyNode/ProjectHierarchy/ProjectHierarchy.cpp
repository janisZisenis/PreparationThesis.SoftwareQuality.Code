#include "ProjectHierarchy.h"
#include "model/modelException.h"

std::shared_ptr<ProjectHierarchy> ProjectHierarchy::getNewInstance() {
    return ProjectHierarchyPtr(new ProjectHierarchy());
}
ProjectHierarchy::~ProjectHierarchy() {}
ProjectHierarchy::ProjectHierarchy() : HierarchyNode("",""){}

std::vector<HierarchyNodePtr> ProjectHierarchy::getNodes() {
    return this->children;
}

void ProjectHierarchy::insertChild(HierarchyNodePtr child, int index) {
    children.insert(children.begin() + index, child);
    childInserted(child, index);
    notify();
}

void ProjectHierarchy::addChild(HierarchyNodePtr child) {
    insertChild(child, children.size());
}

void ProjectHierarchy::removeChild(HierarchyNodePtr child) {
    std::vector<HierarchyNodePtr>::iterator it;
    it = std::find(children.begin(), children.end(), child);

    if(it == children.end()) return;

    int index = it - children.begin();
    children.erase(it);

    childRemoved(child, index);
    notify();
}

ProjectHierarchyPtr ProjectHierarchy::sharedFromThis() {
    ProjectHierarchyPtr me = std::dynamic_pointer_cast<ProjectHierarchy>(this->sharedFromThis());
    if (!me) throw new SharedFromThisException();
    return me;
}

