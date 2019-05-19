#ifndef MODEL_HIERARCHYNODEFACTORY_H
#define MODEL_HIERARCHYNODEFACTORY_H

#include <sstream>

class HierarchyNode;

class HierarchyNodeFactory;
typedef std::shared_ptr<HierarchyNodeFactory> HierarchyNodeFactoryPtr;
class HierarchyNodeFactory {
public:
    virtual  ~HierarchyNodeFactory() {};

protected:
    HierarchyNodeFactory() {};

public:
    virtual std::shared_ptr<HierarchyNode> makeHierarchyNode(std::string type) = 0;
    virtual std::vector<std::string> getNodeTypes() = 0;
};

class InvalidHierarchyNodeType : public std::exception {
    const char *what() const throw() {
        std::ostringstream getNr;
        getNr << "Invalid type for HierarchyNode!";
        return getNr.str().c_str();
    }
};

#endif //MODEL_HIERARCHYNODEFACTORY_H