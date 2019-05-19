#ifndef ITEM_COORDINATESYSTEMITEM_H
#define ITEM_COORDINATESYSTEMITEM_H


#include "item/HierarchicItem/TreeItem/TreeItem.h"

class HierarchyNode;
class CoordinateSystem;

struct CoordinateSystemChildInfoStruct {
	enum CoordinateSystemChildInfo { INVALID = -1, NUMBER_OF_CHILDS = 0 };
};
typedef CoordinateSystemChildInfoStruct::CoordinateSystemChildInfo CoordinateSystemChildInfo;

class CoordinateSystemItem;
typedef std::shared_ptr<CoordinateSystemItem> CoordinateSystemItemPtr;
class CoordinateSystemItem : public TreeItem {
public:
	static CoordinateSystemItemPtr getNewInstance(std::shared_ptr<CoordinateSystem> node, std::shared_ptr<TreeItemFactory> itemFactory);
	virtual ~CoordinateSystemItem();
protected:
	CoordinateSystemItem(std::shared_ptr<CoordinateSystem> node, std::shared_ptr<TreeItemFactory> itemFactory);
public:
	virtual int getChildCount() override;
	virtual HierarchicItemPtr getChildAt(int row) override;

	virtual std::string getType() override;
	virtual std::string getName() override;

	virtual std::shared_ptr<HierarchyNode> getNode() override;

	virtual int childPos(HierarchicItemPtr child) override;
private:
	CoordinateSystemItemPtr sharedFromThis();

	std::shared_ptr<CoordinateSystem> node;
};

#endif //ITEM_COORDINATESYSTEMITEM_H;ITEM_H