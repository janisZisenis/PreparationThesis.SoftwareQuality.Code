#ifndef ITEM_TABLEROOT_H
#define ITEM_TABLEROOT_H

#include "TableItem.h"
#include <item/item_Export.h>

class TableRoot;
typedef std::shared_ptr<TableRoot> TableRootPtr;

class item_EXPORT TableRoot : public TableItem {
public:
	static TableRootPtr getNewInstance();
	virtual ~TableRoot();
protected:
	TableRoot();
public:
	virtual int getChildCount() override;
	virtual HierarchicItemPtr getChildAt(int row) override;
	virtual int childPos(HierarchicItemPtr child) override;
	virtual void appendChild(TableItemPtr child);

	std::string getFirstColumn() override;
	std::string getPropertyName() override;
	std::string getPropertyValue() override;
private:
	TableRootPtr sharedFromThis();

	std::vector<std::shared_ptr<TableItem> > children;
};


#endif //ITEM_TABLEROOT_H