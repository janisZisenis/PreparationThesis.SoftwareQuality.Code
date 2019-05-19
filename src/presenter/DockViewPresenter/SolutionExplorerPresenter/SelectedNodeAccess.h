#ifndef PRESENTER_SELECTEDNODEACCESS_H
#define PRESENTER_SELECTEDNODEACCESS_H

#include <memory>

class HierarchyNode;

class SelectedNodeAccess;
typedef std::shared_ptr<SelectedNodeAccess> SelectedNodeAccessPtr;
class SelectedNodeAccess {
public:
    virtual ~SelectedNodeAccess() {};
protected:
    SelectedNodeAccess() {};
    
public:
    virtual std::shared_ptr<HierarchyNode> getSelectedNode() = 0;
};


#endif //PRESENTER_SELECTEDNODEACCESS_H