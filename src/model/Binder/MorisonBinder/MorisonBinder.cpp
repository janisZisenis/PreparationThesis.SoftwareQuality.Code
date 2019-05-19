#include "MorisonBinder.h"
#include "model/HierarchyNode/Morison/Morison.h"

MorisonBinderPtr MorisonBinder::getNewInstance(MorisonPtr node) {
    return MorisonBinderPtr(new MorisonBinder(node));
}

MorisonBinder::~MorisonBinder() {}

MorisonBinder::MorisonBinder(MorisonPtr node) : child(node) {}