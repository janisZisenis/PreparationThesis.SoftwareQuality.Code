#ifndef PRESENTER_VIEWFACTORY_H
#define PRESENTER_VIEWFACTORY_H

#include <presenter/presenter_Export.h>
#include <vector>
#include <memory>
#include <string>

class HierarchyNode;
class View;

class ViewFactory;
typedef std::shared_ptr<ViewFactory> ViewFactoryPtr;

class presenter_EXPORT ViewFactory {
public:
    virtual ~ViewFactory() {};
protected:
    ViewFactory() {};

public:
    virtual std::vector<std::string> getListOfVisualizationsFor(std::string type) = 0;
    virtual View* makeView(std::string type, std::shared_ptr<HierarchyNode> node) = 0;
};

#endif //PRESENTER_VIEWFACTORY_H