#include "TableItem.h"

TableItem::~TableItem() {}
TableItem::TableItem() {}

TableItemPtr TableItem::sharedFromThis() {
    TableItemPtr me = std::dynamic_pointer_cast<TableItem>(this->shared_from_this());
    if(!me) throw new SharedFromThisException();
    return me;
}
