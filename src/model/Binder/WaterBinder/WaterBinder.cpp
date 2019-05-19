#include "WaterBinder.h"
#include "model/HierarchyNode/Water/Water.h"

#include "model/HierarchyNode/Morison/Morison.h"
#include "model/HierarchyNode/SedimentTransport/SedimentTransport.h"

WaterBinderPtr WaterBinder::getNewInstance(WaterPtr node) {
    return WaterBinderPtr(new WaterBinder(node));
}

WaterBinder::~WaterBinder() {}

WaterBinder::WaterBinder(WaterPtr node) : child(node){}

void WaterBinder::visit(MorisonPtr morison) {
    WaterPtr oldChild = morison->getWater();

    morison->setWater(child);

    this->child = oldChild;
}

void WaterBinder::visit(std::shared_ptr<SedimentTransport> sedimentTransport) {
    WaterPtr oldChild = sedimentTransport->getWater();

    sedimentTransport->setWater(child);

    this->child = oldChild;
}
