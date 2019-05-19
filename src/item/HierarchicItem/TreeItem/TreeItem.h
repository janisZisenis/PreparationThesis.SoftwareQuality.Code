#ifndef ITEM_TREEITEM_H
#define ITEM_TREEITEM_H

#include <item/item_Export.h>
#include <item/HierarchicItem/HierarchicItem.h>

class HierarchyNode;
class TreeItemFactory;

class TreeItem;
typedef std::shared_ptr<TreeItem> TreeItemPtr;

class item_EXPORT TreeItem : public HierarchicItem {
public:
	virtual ~TreeItem();
protected:
	TreeItem(std::shared_ptr<TreeItemFactory> itemFactory);

protected: //slots
	virtual void onChildNodeInserted(const std::shared_ptr<HierarchyNode> inserted, const int index);
	virtual void onChildNodeRemoved(const std::shared_ptr<HierarchyNode> removed, const int index);
	virtual void onChildNodeReplaced(const std::shared_ptr<HierarchyNode> newChild, const std::string type);
	virtual void onNodeChanged(const std::shared_ptr<HierarchyNode> changed);

public:
	virtual std::string getType() = 0;
	virtual std::string getName() = 0;
    virtual std::shared_ptr<HierarchyNode> getNode() = 0;

protected:
    void connectToNode(std::shared_ptr<HierarchyNode> node);
    void disconnectFromNode(std::shared_ptr<HierarchyNode> node);
private:
	TreeItemPtr sharedFromThis();

protected:
    std::shared_ptr<TreeItemFactory> itemFactory;
};

#endif //ITEM_TREEITEM_H