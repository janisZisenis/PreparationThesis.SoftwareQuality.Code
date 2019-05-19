#ifndef MODEL_HIERARCHYNODEFACTORYIMP_H
#define MODEL_HIERARCHYNODEFACTORYIMP_H

#include <model/model_Export.h>
#include <utilities/Object/Object.h>

#include <model/HierarchyNodeFactory/HierarchyNodeFactory.h>

class HierarchyNodeFactoryImp;
typedef std::shared_ptr<HierarchyNodeFactoryImp> HierarchyNodeFactoryImpPtr;
class model_EXPORT HierarchyNodeFactoryImp : public HierarchyNodeFactory , public Object {
public:
    static HierarchyNodeFactoryImpPtr getNewInstance();
    virtual  ~HierarchyNodeFactoryImp();
private:
    HierarchyNodeFactoryImp();

public:
    virtual std::shared_ptr<HierarchyNode> makeHierarchyNode(std::string type);
    virtual std::vector<std::string> getNodeTypes();

private:
    void initializeNodeTypes();

    std::vector<std::string> nodeTypes;
};

#endif //MODEL_HIERARCHYNODEFACTORYIMP_H