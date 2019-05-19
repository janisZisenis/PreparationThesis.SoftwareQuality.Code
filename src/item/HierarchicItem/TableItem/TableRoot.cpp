#include "TableRoot.h"

TableRootPtr TableRoot::getNewInstance() {
    return TableRootPtr(new TableRoot());
}
TableRoot::~TableRoot() {}
TableRoot::TableRoot() {}

int TableRoot::getChildCount() {
    return (int) children.size();
}

HierarchicItemPtr TableRoot::getChildAt(int row) {
	if (row <= -1 || row >= children.size())
		return nullptr;
	return children[row];
}

void TableRoot::appendChild(TableItemPtr child) {
    children.push_back(child);
    child->setParent(sharedFromThis());
}

int TableRoot::childPos(HierarchicItemPtr child) {
    std::vector<TableItemPtr>::iterator it;
    it = find(children.begin(), children.end(), child);
    if (it != children.end())
        return it - children.begin();
    return 0;
}

std::string TableRoot::getFirstColumn() {
    return "";
}

std::string TableRoot::getPropertyName() {
    return "";
}

std::string TableRoot::getPropertyValue() {
    return "";
}

TableRootPtr TableRoot::sharedFromThis() {
    TableRootPtr me = std::dynamic_pointer_cast<TableRoot>(this->shared_from_this());
    if (!me) throw new SharedFromThisException();
    return me;
}