#ifndef ITEM_PROPERTIESITEM_H
#define ITEM_PROPERTIESITEM_H

#include <item/item_Export.h>
#include <item/HierarchicItem/TableItem/TableItem.h>

class PropertiesItem;
typedef std::shared_ptr<PropertiesItem> PropertiesItemPtr;
class item_EXPORT PropertiesItem : public TableItem {
public:
    static PropertiesItemPtr getNewInstance(std::string propertyName, std::string propertyValue, std::string unit);
    virtual ~PropertiesItem();
protected:
    PropertiesItem(std::string propertyName, std::string propertyValue, std::string unit);

public:
    virtual HierarchicItemPtr getChildAt(int pos) override;
    virtual int getChildCount() override;
    virtual int childPos(HierarchicItemPtr child) override;

    std::string getFirstColumn() override;
    std::string getPropertyName() override;
    std::string getPropertyValue() override;
    PropertiesItemPtr sharedFromThis();

private:
    std::string propertyName;
    std::string propertyValue;
    std::string unit;
};


#endif //ITEM_LEAFITEM_H
