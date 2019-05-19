#ifndef ITEM_TABLEITEM_H
#define ITEM_TABLEITEM_H

#include <item/item_Export.h>
#include <item/HierarchicItem/HierarchicItem.h>

class HierarchyNode;

class TableItem;
typedef std::shared_ptr<TableItem> TableItemPtr;

class TableItem : public HierarchicItem {
public:
	virtual ~TableItem();
protected:
	TableItem();

public:
	virtual std::string getFirstColumn() = 0;
	virtual std::string getPropertyName() = 0;
    virtual std::string getPropertyValue() = 0;

private:
	TableItemPtr sharedFromThis();
};

#endif //ITEM_TABLEITEM_H