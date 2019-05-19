#ifndef PRESENTER_ROOTBUILDERFACTORY_H
#define PRESENTER_ROOTBUILDERFACTORY_H

#include <memory>
#include <presenter/presenter_Export.h>

class RootBuilder;
class HierarchyNode;

class RootBuilderFactory;
typedef std::shared_ptr<RootBuilderFactory> RootBuilderFactoryPtr;
class presenter_EXPORT RootBuilderFactory {
public:
    virtual ~RootBuilderFactory(){};
protected:
    RootBuilderFactory(){};

public:
    virtual std::shared_ptr<RootBuilder> makeRootBuilder(std::shared_ptr<HierarchyNode> node) = 0;
};

#endif //PRESENTER_ROOTBUILDERFACTORY_H