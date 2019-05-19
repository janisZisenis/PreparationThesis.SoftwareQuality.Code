#include "CompositeImp.h"


CompositeImpPtr CompositeImp::getNewInstance() {
    return CompositeImpPtr(new CompositeImp());
}
CompositeImp::~CompositeImp() {}
CompositeImp::CompositeImp() {}

void CompositeImp::insertChild(CompositePtr child, int index) {
    child->setParent(sharedFromThis());
    children.insert(children.begin() + index, child);
}

void CompositeImp::appendChild(CompositePtr child) {
    insertChild(child, children.size());
}

void CompositeImp::setChildAt(CompositePtr child, int index) {
    if(index >= children.size()) return;

    children.erase(children.begin() + index);
    children.insert(children.begin() + index, child);
}

void CompositeImp::removeChild(int index) {
    children[index]->setParent(nullptr);
    children.erase(children.begin() + index);
}

CompositePtr CompositeImp::getChildAt(int pos) {
    if(pos >= children.size()) return nullptr;
    return children[pos];
}

int CompositeImp::getChildCount() {
    return children.size();
}

int CompositeImp::childPos(CompositePtr child) {
    std::vector<CompositePtr>::iterator it = std::find(children.begin(), children.end(), child);

    if (it != children.end()) return it - children.begin();
    return -1;
}

CompositeImpPtr CompositeImp::sharedFromThis() {
    CompositeImpPtr me = std::dynamic_pointer_cast<CompositeImp>(this->shared_from_this());
    if (!me) throw new SharedFromThisException();
    return me;
}


