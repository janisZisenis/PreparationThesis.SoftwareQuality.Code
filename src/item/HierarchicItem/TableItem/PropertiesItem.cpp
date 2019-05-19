#include "PropertiesItem.h"
#include <utilities/String/String.h>

PropertiesItemPtr PropertiesItem::getNewInstance(std::string propertyName, std::string propertyValue, std::string unit) {
    return PropertiesItemPtr(new PropertiesItem(propertyName, propertyValue, unit));
}
PropertiesItem::~PropertiesItem() {}
PropertiesItem::PropertiesItem(std::string propertyName, std::string propertyValue, std::string unit)
        : propertyName(propertyName), propertyValue(propertyValue), unit(unit) {}

HierarchicItemPtr PropertiesItem::getChildAt(int pos) {
    return nullptr;
}

int PropertiesItem::getChildCount() {
    return 0;
}

int PropertiesItem::childPos(HierarchicItemPtr child) {
    return -1;
}

std::string PropertiesItem::getFirstColumn() {
    return utilities::String::trim(propertyName + " " + unit);
}

std::string PropertiesItem::getPropertyName() {
    return this->propertyName;
}

std::string PropertiesItem::getPropertyValue() {
    return this->propertyValue;
}

PropertiesItemPtr PropertiesItem::sharedFromThis() {
    PropertiesItemPtr me = std::dynamic_pointer_cast<PropertiesItem>(this->shared_from_this());
    if (!me) throw new SharedFromThisException();
    return me;
}
