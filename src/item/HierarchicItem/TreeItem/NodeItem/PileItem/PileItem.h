#ifndef ITEM_PILEITEM_H
#define ITEM_PILEITEM_H

#include "item/HierarchicItem/TreeItem/TreeItem.h"

class Pile;

struct PileChildInfoStruct {
	enum PileChildInfo { INVALID = -1, NUMBER_OF_CHILDS = 0 };
};
typedef PileChildInfoStruct::PileChildInfo PileChildInfo;

class PileItem;
typedef std::shared_ptr<PileItem> PileItemPtr;

class PileItem : public TreeItem {
public:
	static PileItemPtr getNewInstance(std::shared_ptr<Pile> node, std::shared_ptr<TreeItemFactory> itemFactory);
	virtual ~PileItem();
protected:
	PileItem(std::shared_ptr<Pile> node, std::shared_ptr<TreeItemFactory> itemFactory);

public:
	virtual int getChildCount() override;
    virtual int childPos(HierarchicItemPtr child) override;
	virtual HierarchicItemPtr getChildAt(int row) override;

	virtual std::string getName() override;
	virtual std::string getType() override;

	virtual std::shared_ptr<HierarchyNode> getNode() override;

private:
	PileItemPtr sharedFromThis();

    std::shared_ptr<Pile> node;
};


#endif //ITEM_PILEITEM_H