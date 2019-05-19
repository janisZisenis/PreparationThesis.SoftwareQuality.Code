#ifndef ITEM_PROJECTHIERARCHYITEM_H
#define ITEM_PROJECTHIERARCHYITEM_H

#include "item/HierarchicItem/TreeItem/TreeItem.h"
#include <vector>

class ProjectHierarchy;

class ProjectHierarchyItem;
typedef std::shared_ptr<ProjectHierarchyItem> ProjectHierarchyItemPtr;

class item_EXPORT ProjectHierarchyItem : public TreeItem {
public:
	static ProjectHierarchyItemPtr getNewInstance(std::shared_ptr<ProjectHierarchy> node, std::shared_ptr<TreeItemFactory> itemFactory);
	virtual ~ProjectHierarchyItem();

protected:
	ProjectHierarchyItem(std::shared_ptr<ProjectHierarchy> node, std::shared_ptr<TreeItemFactory> itemFactory);

protected: //slots
	virtual void onChildNodeInserted(const std::shared_ptr<HierarchyNode> inserted, const int index) override;
	virtual void onChildNodeRemoved(const std::shared_ptr<HierarchyNode> removed, const int index) override;

public:
	virtual void insertChild(HierarchicItemPtr item, int index);
	virtual void removeChild(int index);

	virtual int getChildCount() override;
	virtual int childPos(HierarchicItemPtr child) override;
	virtual HierarchicItemPtr getChildAt(int row) override;

	virtual std::string getName() override;
	virtual std::string getType() override;

	virtual std::shared_ptr<HierarchyNode> getNode() override;
private:
	ProjectHierarchyItemPtr sharedFromThis();

protected:
	std::shared_ptr<ProjectHierarchy> node;
	std::vector<HierarchicItemPtr> children;
};


#endif //ITEM_PROJECTHIERARCHYITEM_H