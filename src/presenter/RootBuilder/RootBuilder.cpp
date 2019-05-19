#include "RootBuilder.h"
#include <model/HierarchyNode/HierarchyNodeProperties.h>
#include <model/HierarchyNode/HierarchyNode.h>
#include <item/HierarchicItem/TableItem/TableItem.h>
#include <item/HierarchicItem/TableItem/PropertiesItem.h>
#include <item/HierarchicItem/TableItem/TableRoot.h>
#include <model/HierarchyNode/Units.h>


RootBuilderPtr RootBuilder::getNewInstance() {
    return RootBuilderPtr(new RootBuilder());
}
RootBuilder::~RootBuilder() {}
RootBuilder::RootBuilder() : root(makeTableRoot()){}

TableRootPtr RootBuilder::makeTableRoot() {
    return TableRoot::getNewInstance();
}

TableItemPtr RootBuilder::makeImmutableItem(std::string propertyName, std::string propertyValue, std::string unit) {
    TableItemPtr item = makeMutableItem(propertyName, propertyValue, Units::noUnit());
    item->disableEditing();
    return item;
}

TableItemPtr RootBuilder::makeMutableItem(std::string propertyName, std::string propertyValue, std::string unit) {
    return PropertiesItem::getNewInstance(propertyName, propertyValue, unit);
}

TableItemPtr RootBuilder::buildRoot() {
    return root;
}

TableItemPtr RootBuilder::makeDummyItem(std::string type) {
    return makeImmutableItem(type, HierarchyNodeProperties::emptyChild(), Units::noUnit());
}

void RootBuilder::addNodeInfo(HierarchyNodePtr node) {
    root->appendChild(makeImmutableItem(HierarchyNodeProperties::type(), node->getType(), Units::noUnit()));
    root->appendChild(makeMutableItem(HierarchyNodeProperties::name(), node->getName(),  Units::noUnit()));
}

void RootBuilder::addChildInfo(HierarchyNodePtr child, std::string type) {
    if(!child) root->appendChild(makeDummyItem(type));
    else root->appendChild(makeImmutableItem(type, child->getName(),  Units::noUnit()));
}
