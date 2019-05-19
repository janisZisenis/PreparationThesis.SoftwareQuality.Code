#ifndef ITEM_WATERITEM_H
#define ITEM_WATERITEM_H

#include "item/HierarchicItem/TreeItem/TreeItem.h"

class Water;

struct WaterChildInfoStruct {
	enum WaterChildInfo { INVALID = -1, NUMBER_OF_CHILDS = 0 };
};
typedef WaterChildInfoStruct::WaterChildInfo WaterChildInfo;

class WaterItem;
typedef std::shared_ptr<WaterItem> WaterItemPtr;

class item_EXPORT WaterItem : public TreeItem
{
public:
	static WaterItemPtr getNewInstance(std::shared_ptr<Water> node, std::shared_ptr<TreeItemFactory> itemFactory);
	virtual ~WaterItem();
protected:
	WaterItem(std::shared_ptr<Water> node, std::shared_ptr<TreeItemFactory> itemFactory);
public:
	virtual int getChildCount() override;
	virtual HierarchicItemPtr getChildAt(int row) override;

	virtual std::string getName() override;
	virtual std::string getType() override;

	virtual std::shared_ptr<HierarchyNode> getNode() override;

protected:
	virtual int childPos(HierarchicItemPtr child) override;
private:
	WaterItemPtr sharedFromThis();

	std::shared_ptr<Water> node;
};


#endif //ITEM_WATERITEM_H