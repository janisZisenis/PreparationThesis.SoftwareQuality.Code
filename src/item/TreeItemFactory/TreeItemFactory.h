#ifndef ITEM_TREEITEMFACTORY_H
#define ITEM_TREEITEMFACTORY_H

#include <memory>
#include <string>

class TreeItem;
class HierarchyNode;

class TreeItemFactory;
typedef std::shared_ptr<TreeItemFactory> TreeItemFactoryPtr;
class TreeItemFactory {
public:
    virtual ~TreeItemFactory() {};
protected:
    TreeItemFactory() {};

public:
    virtual std::shared_ptr<TreeItem> makeTreeItem(std::shared_ptr<HierarchyNode> node, std::string type) = 0;
};

#endif //ITEM_TREEITEMFACTORY_H