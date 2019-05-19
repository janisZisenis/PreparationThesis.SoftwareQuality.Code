#ifndef PRESENTER_ROOTBUILDER_H
#define PRESENTER_ROOTBUILDER_H

#include <presenter/presenter_Export.h>
#include <memory>
#include <string>

class TableItem;
class HierarchyNode;
class TableRoot;

class RootBuilder;
typedef std::shared_ptr<RootBuilder> RootBuilderPtr;
class presenter_EXPORT RootBuilder {
public:
    virtual ~RootBuilder();
public:
    static RootBuilderPtr getNewInstance();
    virtual std::shared_ptr<TableItem> buildRoot();
protected:
    RootBuilder();

protected:
    virtual std::shared_ptr<TableRoot> makeTableRoot();
    virtual std::shared_ptr<TableItem> makeImmutableItem(std::string propertyName, std::string propertyValue, std::string unit);
    virtual std::shared_ptr<TableItem> makeMutableItem(std::string propertyName, std::string propertyValue, std::string unit);
    virtual std::shared_ptr<TableItem> makeDummyItem(std::string type);

    virtual void addNodeInfo(std::shared_ptr<HierarchyNode> node);
    virtual void addChildInfo(std::shared_ptr<HierarchyNode> child, std::string type);

    std::shared_ptr<TableRoot> root;
};

#endif //PRESENTER_ROOTBUILDER_H