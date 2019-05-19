#ifndef ITEM_TREEITEMFACTORYIMP_H
#define ITEM_TREEITEMFACTORYIMP_H

#include "TreeItemFactory.h"
#include <utilities/Object/Object.h>
#include <item/item_Export.h>

class TreeItemFactoryImp;
typedef std::shared_ptr<TreeItemFactoryImp> TreeItemFactoryImpPtr;
class item_EXPORT TreeItemFactoryImp : public TreeItemFactory, public Object {
public:
	static TreeItemFactoryImpPtr getNewInstance();
	virtual ~TreeItemFactoryImp();
protected:
	TreeItemFactoryImp();

public:
	virtual std::shared_ptr<TreeItem> makeTreeItem(std::shared_ptr<HierarchyNode> node, std::string type) override;

private:
	virtual std::shared_ptr<TreeItem> makeDummyItem(std::string type);

	virtual std::shared_ptr<TreeItem> makeCoordinateSystemItem(std::shared_ptr<HierarchyNode> node);
    virtual std::shared_ptr<TreeItem> makeMorisonItem(std::shared_ptr<HierarchyNode> node);
    virtual std::shared_ptr<TreeItem> makePileItem(std::shared_ptr<HierarchyNode> node);
	virtual std::shared_ptr<TreeItem> makeSedimentItem(std::shared_ptr<HierarchyNode> node);
	virtual std::shared_ptr<TreeItem> makeWaterItem(std::shared_ptr<HierarchyNode> node);
    virtual std::shared_ptr<TreeItem> makeWaveDynamicItem(std::shared_ptr<HierarchyNode> node);
	virtual std::shared_ptr<TreeItem> makeWaveItem(std::shared_ptr<HierarchyNode> node);
	virtual std::shared_ptr<TreeItem> makeSedimentTransport(std::shared_ptr<HierarchyNode> node);

    TreeItemFactoryImpPtr sharedFromThis();
};

#endif //ITEM_TREEITEMFACTORYIMP_H