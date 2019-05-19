#include "Leaf.h"

LeafPtr Leaf::getNewInstance() {
    return LeafPtr(new Leaf());
}
Leaf::~Leaf() {}
Leaf::Leaf() {}

void Leaf::insertChild(CompositePtr child, int index) {}
void Leaf::appendChild(CompositePtr child) {}
void Leaf::setChildAt(CompositePtr child, int index) {}
void Leaf::removeChild(int index) {}

CompositePtr Leaf::getChildAt(int pos) { return nullptr; }
int Leaf::getChildCount() { return 0; }
int Leaf::childPos(CompositePtr child) { return -1; }

LeafPtr Leaf::sharedFromThis() {
    LeafPtr me = std::dynamic_pointer_cast<Leaf>(this->shared_from_this());
    if(!me) throw new SharedFromThisException();
    return me;
}




