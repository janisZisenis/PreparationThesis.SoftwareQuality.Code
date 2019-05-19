#ifndef ITEM_SEDIMENTTRANSPORTITEM_H
#define ITEM_SEDIMENTTRANSPORTITEM_H

#include "item/HierarchicItem/TreeItem/TreeItem.h"

class SedimentTransport;

struct SedimentTransportChildInfoStruct {
	enum SedimentTransportChildInfo { INVALID = -1, WAVEDYNAMIC = 0, SEDIMENT = 1, WATER = 2, NUMBER_OF_CHILDS = 3 };
};
typedef SedimentTransportChildInfoStruct::SedimentTransportChildInfo SedimentTransportChildInfo;

class SedimentTransportItem;
typedef std::shared_ptr<SedimentTransportItem> SedimentTransportItemPtr;
class item_EXPORT SedimentTransportItem : public TreeItem {
public:
	static SedimentTransportItemPtr getNewInstance(std::shared_ptr<SedimentTransport> node, std::shared_ptr<TreeItemFactory> itemFactory);
	virtual ~SedimentTransportItem();
protected:
	SedimentTransportItem(std::shared_ptr<SedimentTransport> node, std::shared_ptr<TreeItemFactory> itemFactory);

protected: //slots
	virtual void onChildNodeReplaced(const std::shared_ptr<HierarchyNode> newChild, const std::string type) override;

public:
	virtual HierarchicItemPtr getChildAt(int row) override;
    virtual void setChild(HierarchicItemPtr child, SedimentTransportChildInfo type);
    virtual int getChildCount() override;
    virtual int childPos(HierarchicItemPtr child) override;

	virtual std::string getName() override;
	virtual std::string getType() override;

	virtual std::shared_ptr<HierarchyNode> getNode() override;

private:
	virtual SedimentTransportChildInfo getChildIndex(std::string roleName);

	SedimentTransportItemPtr sharedFromThis();
    std::shared_ptr<SedimentTransport> node;

	HierarchicItemPtr items[SedimentTransportChildInfo::NUMBER_OF_CHILDS];
};


#endif //ITEM_SEDIMENTTRANSPORTITEM_H