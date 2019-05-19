#ifndef ITEM_MORISONITEM_H
#define ITEM_MORISONITEM_H

#include "item/HierarchicItem/TreeItem/TreeItem.h"

class Morison;

struct MorisonChildInfoStruct {
	enum MorisonChildInfo { INVALID = -1, WAVEDYNAMIC = 0, PILE = 1, WATER = 2, NUMBER_OF_CHILDS = 3 };
};
typedef MorisonChildInfoStruct::MorisonChildInfo MorisonChildInfo;

class MorisonItem;
typedef std::shared_ptr<MorisonItem> MorisonItemPtr;
class item_EXPORT MorisonItem : public TreeItem {
public:
	static MorisonItemPtr getNewInstance(std::shared_ptr<Morison> node, std::shared_ptr<TreeItemFactory> itemFactory);
	virtual ~MorisonItem();
protected:
	MorisonItem(std::shared_ptr<Morison> node, std::shared_ptr<TreeItemFactory> itemFactory);

protected: //slots
	virtual void onChildNodeReplaced(const std::shared_ptr<HierarchyNode> newChild, const std::string type) override;

public:
	virtual HierarchicItemPtr getChildAt(int row) override;
	virtual void setChild(HierarchicItemPtr child, MorisonChildInfo type);
	virtual int getChildCount() override;
	virtual int childPos(HierarchicItemPtr child) override;

	virtual std::string getName() override;
	virtual std::string getType() override;

	virtual std::shared_ptr<HierarchyNode> getNode() override;

private:
	virtual MorisonChildInfo getChildIndex(std::string roleName);

	MorisonItemPtr sharedFromThis();
	std::shared_ptr<Morison> node;

	HierarchicItemPtr items[MorisonChildInfo::NUMBER_OF_CHILDS];
};


#endif //ITEM_MORISONITEM_H