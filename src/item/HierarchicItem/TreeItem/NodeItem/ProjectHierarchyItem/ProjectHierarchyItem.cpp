#include "ProjectHierarchyItem.h"
#include <item/TreeItemFactory/TreeItemFactory.h>
#include "model/HierarchyNode/ProjectHierarchy/ProjectHierarchy.h"

ProjectHierarchyItemPtr ProjectHierarchyItem::getNewInstance(ProjectHierarchyPtr node, TreeItemFactoryPtr itemFactory) {
	return ProjectHierarchyItemPtr(new ProjectHierarchyItem(node, itemFactory));
}
ProjectHierarchyItem::~ProjectHierarchyItem() {
	disconnectFromNode(node);
}
ProjectHierarchyItem::ProjectHierarchyItem(ProjectHierarchyPtr node, TreeItemFactoryPtr itemFactory) : TreeItem(itemFactory), node(node) {
	connectToNode(node);
}

void ProjectHierarchyItem::onChildNodeInserted(const HierarchyNodePtr inserted, const int index) {
    insertChild(itemFactory->makeTreeItem(inserted, inserted->getType()), index);
}

void ProjectHierarchyItem::onChildNodeRemoved(const HierarchyNodePtr removed, const int index) {
	removeChild(index);
}

void ProjectHierarchyItem::insertChild(HierarchicItemPtr item, int index) {
    beginInsertChild(sharedFromThis(), index);
    connectToChild(item);
    this->children.insert(children.begin() + index, item);
    endInsertChild();
}
void ProjectHierarchyItem::removeChild(int index) {
    beginRemoveChild(sharedFromThis(), index);
    disconnectFromChild(children[index]);
    this->children.erase(children.begin() + index);
    endRemoveChild();
}

int ProjectHierarchyItem::getChildCount() {
	return (int)children.size();
}

HierarchicItemPtr ProjectHierarchyItem::getChildAt(int row) {
	if (row < 0 || row >= children.size())
		return nullptr;
	return children[row];
}

std::string ProjectHierarchyItem::getName() {
	return node->getName();
}
std::string ProjectHierarchyItem::getType() {
	return node->getType();
}

HierarchyNodePtr ProjectHierarchyItem::getNode() {
	return node;
}

int ProjectHierarchyItem::childPos(HierarchicItemPtr child) {
	std::vector<HierarchicItemPtr>::iterator it = std::find(children.begin(), children.end(), child);
	if (it != children.end()) return it - children.begin();

	return -1;
}

ProjectHierarchyItemPtr ProjectHierarchyItem::sharedFromThis() {
	ProjectHierarchyItemPtr me = std::dynamic_pointer_cast<ProjectHierarchyItem>(this->shared_from_this());
	if (!me) throw new SharedFromThisException();
	return me;
}

