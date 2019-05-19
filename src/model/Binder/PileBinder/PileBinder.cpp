#include "PileBinder.h"
#include "model/HierarchyNode/Pile/Pile.h"

#include "model/HierarchyNode/Morison/Morison.h"

PileBinderPtr PileBinder::getNewInstance(PilePtr node) {
    return PileBinderPtr(new PileBinder(node));
}

PileBinder::~PileBinder() {}

PileBinder::PileBinder(PilePtr node) : child(node) {}

void PileBinder::visit(MorisonPtr morison) {
   PilePtr oldChild = morison->getPile();

    morison->setPile(child);

    this->child = oldChild;
}