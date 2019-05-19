#ifndef ITEM_WAVEDYNAMICITEM_H
#define ITEM_WAVEDYNAMICITEM_H

#include "item/HierarchicItem/TreeItem/TreeItem.h"

class WaveDynamic;

struct WaveDynamicChildInfoStruct {
	enum WaveDynamicChildInfo { INVALID = -1, COORDINATESYSTEM = 0, WAVE = 1, NUMBER_OF_CHILDS = 2 };
};
typedef WaveDynamicChildInfoStruct::WaveDynamicChildInfo WaveDynamicChildInfo;

class WaveDynamicItem;
typedef std::shared_ptr<WaveDynamicItem> WaveDynamicItemPtr;
class item_EXPORT WaveDynamicItem : public TreeItem {
public:
	static WaveDynamicItemPtr getNewInstance(std::shared_ptr<WaveDynamic> node, std::shared_ptr<TreeItemFactory> itemFactory);
	virtual ~WaveDynamicItem();
protected:
	WaveDynamicItem(std::shared_ptr<WaveDynamic> node, std::shared_ptr<TreeItemFactory> itemFactory);

protected: //slots
	virtual void onChildNodeReplaced(const std::shared_ptr<HierarchyNode> newChild, const std::string type) override;

public:
	virtual HierarchicItemPtr getChildAt(int row) override;
	virtual void setChild(HierarchicItemPtr child, WaveDynamicChildInfo type);
	virtual int getChildCount() override;
    virtual int childPos(HierarchicItemPtr child) override;

	virtual std::string getName() override;
	virtual std::string getType() override;

	virtual std::shared_ptr<HierarchyNode> getNode() override;

private:
	virtual WaveDynamicChildInfo getChildIndex(std::string roleName);

	WaveDynamicItemPtr sharedFromThis();
    std::shared_ptr<WaveDynamic> node;

	HierarchicItemPtr items[WaveDynamicChildInfo::NUMBER_OF_CHILDS];
};


#endif //ITEM_WAVEDYNAMICITEM_H