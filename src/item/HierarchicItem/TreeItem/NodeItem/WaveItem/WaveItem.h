#ifndef ITEM_WAVEITEM_H
#define ITEM_WAVEITEM_H

#include "item/HierarchicItem/TreeItem/TreeItem.h"

class Wave;

struct WaveChildInfoStruct {
	enum WaveChildInfo { INVALID = -1, NUMBER_OF_CHILDS = 0 };
};
typedef WaveChildInfoStruct::WaveChildInfo WaveChildInfo;

class WaveItem;
typedef std::shared_ptr<WaveItem> WaveItemPtr;
class WaveItem : public TreeItem {
public:
	static WaveItemPtr getNewInstance(std::shared_ptr<Wave> node, std::shared_ptr<TreeItemFactory> itemFactory);
	virtual ~WaveItem();
protected:
	WaveItem(std::shared_ptr<Wave> node, std::shared_ptr<TreeItemFactory> itemFactory);

public:
	virtual int getChildCount() override;
	virtual int childPos(HierarchicItemPtr child) override;
	virtual HierarchicItemPtr getChildAt(int row) override;

	virtual std::string getName() override;
	virtual std::string getType() override;

	std::shared_ptr<HierarchyNode> getNode() override;

private:
	WaveItemPtr sharedFromThis();

	std::shared_ptr<Wave> node;
};


#endif //ITEM_WAVEITEM_H