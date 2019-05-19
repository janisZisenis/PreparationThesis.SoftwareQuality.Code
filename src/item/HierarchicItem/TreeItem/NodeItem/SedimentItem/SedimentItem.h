#ifndef ITEM_SEDIMENTITEM_H
#define ITEM_SEDIMENTITEM_H

#include "item/HierarchicItem/TreeItem/TreeItem.h"

class Sediment;

struct SedimentChildInfoStruct {
	enum SedimentChildInfo { INVALID = -1, NUMBER_OF_CHILDS = 0 };
};
typedef SedimentChildInfoStruct::SedimentChildInfo SedimentChildInfo;

class SedimentItem;
typedef std::shared_ptr<SedimentItem> SedimentItemPtr;

class item_EXPORT SedimentItem : public TreeItem {
public:
	static SedimentItemPtr getNewInstance(std::shared_ptr<Sediment> node, std::shared_ptr<TreeItemFactory> itemFactory);
	virtual ~SedimentItem();
protected:
	SedimentItem(std::shared_ptr<Sediment> node, std::shared_ptr<TreeItemFactory> itemFactory);
public:
	virtual int getChildCount() override;
    virtual int childPos(HierarchicItemPtr child) override;
	virtual HierarchicItemPtr getChildAt(int row) override;

	virtual std::string getName() override;
	virtual std::string getType() override;

	virtual std::shared_ptr<HierarchyNode> getNode() override;

private:
	SedimentItemPtr sharedFromThis();

    std::shared_ptr<Sediment> node;
};


#endif //ITEM_SEDIMENTITEM_H