#ifndef PRESENTER_DEFAULTROOTBUILDER_H
#define PRESENTER_DEFAULTROOTBUILDER_H

#include <presenter/RootBuilder/RootBuilder.h>

class HierarchyNode;

class DefaultRootBuilder;
typedef std::shared_ptr<DefaultRootBuilder> DefaultRootBuilderPtr;
class presenter_EXPORT DefaultRootBuilder : public RootBuilder {
public:
    static DefaultRootBuilderPtr getNewInstance(std::shared_ptr<HierarchyNode> node);
    virtual ~DefaultRootBuilder();
protected:
    DefaultRootBuilder(std::shared_ptr<HierarchyNode> node);
public:
    virtual std::shared_ptr<TableItem> buildRoot();

private:
    std::shared_ptr<HierarchyNode> node;
};

#endif //PRESENTER_DEFAULTROOTBUILDER_H