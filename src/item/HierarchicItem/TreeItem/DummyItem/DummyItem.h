#pragma once
#include "item/HierarchicItem/TreeItem/TreeItem.h"

class DummyItem;
typedef std::shared_ptr<DummyItem> DummyItemPtr;

class DummyItem : public TreeItem {
public:
	static DummyItemPtr getNewInstance(std::string type, std::shared_ptr<TreeItemFactory> itemFactory);
	virtual ~DummyItem();
protected:
	DummyItem(std::string type, std::shared_ptr<TreeItemFactory> itemFactory);

public:
	virtual std::string getType() override;
	virtual std::string getName() override;
	virtual std::shared_ptr<HierarchyNode> getNode() override;

	virtual int getChildCount() override;

	virtual HierarchicItemPtr getChildAt(int row) override;

protected:
	virtual int childPos(HierarchicItemPtr child) override;

private:
	DummyItemPtr sharedFromThis();

	std::string type;
};
