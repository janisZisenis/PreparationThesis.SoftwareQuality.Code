#ifndef PRESENTER_ROOTBUILDERFACTORYIMP_H
#define PRESENTER_ROOTBUILDERFACTORYIMP_H

#include "RootBuilderFactory.h"

class RootBuilderFactoryImp;
typedef std::shared_ptr<RootBuilderFactoryImp> RootBuilderFactoryImpPtr;
class presenter_EXPORT RootBuilderFactoryImp : public RootBuilderFactory {
public:
    static RootBuilderFactoryImpPtr getNewInstance();
    virtual ~RootBuilderFactoryImp();
protected:
    RootBuilderFactoryImp();

public:
    std::shared_ptr<RootBuilder> makeRootBuilder(std::shared_ptr<HierarchyNode> node);

private:
    std::shared_ptr<RootBuilder> makeCoordinateSystemRootBuilder(std::shared_ptr<HierarchyNode> node);
    std::shared_ptr<RootBuilder> makeMorisonRootBuilder(std::shared_ptr<HierarchyNode> node);
    std::shared_ptr<RootBuilder> makePileRootBuilder(std::shared_ptr<HierarchyNode> node);
    std::shared_ptr<RootBuilder> makeSedimentRootBuilder(std::shared_ptr<HierarchyNode> node);
    std::shared_ptr<RootBuilder> makeSedimentTransportRootBuilder(std::shared_ptr<HierarchyNode> node);
    std::shared_ptr<RootBuilder> makeWaterRootBuilder(std::shared_ptr<HierarchyNode> node);
    std::shared_ptr<RootBuilder> makeWaveDynamicRootBuilder(std::shared_ptr<HierarchyNode> node);
    std::shared_ptr<RootBuilder> makeWaveRootBuilder(std::shared_ptr<HierarchyNode> node);

    std::shared_ptr<RootBuilder> makeEmptyRootBuilder();
    std::shared_ptr<RootBuilder> makeDefaultRootBuilder(std::shared_ptr<HierarchyNode> node);
};

#endif //PRESENTER_ROOTBUILDERFACTORYIMP_H