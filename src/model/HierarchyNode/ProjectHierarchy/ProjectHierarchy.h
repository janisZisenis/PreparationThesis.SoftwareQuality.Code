#ifndef MODEL_PROJECTHIERARCHY_H
#define MODEL_PROJECTHIERARCHY_H

#include "model/HierarchyNode/HierarchyNode.h"
#include "AddRemoveNodeService.h"
#include "ProjectHierarchyService.h"
#include <utilities/Observer/Subject.h>

class ProjectHierarchy;
typedef std::shared_ptr<ProjectHierarchy> ProjectHierarchyPtr;

class model_EXPORT ProjectHierarchy : public HierarchyNode, public AddRemoveNodeService, public ProjectHierarchyService, public Subject {
public:
	static ProjectHierarchyPtr getNewInstance();
	virtual ~ProjectHierarchy();

	virtual void insertChild(HierarchyNodePtr child, int index);
	virtual void addChild(HierarchyNodePtr child) override;
	virtual void removeChild(HierarchyNodePtr child) override;

	std::vector<HierarchyNodePtr> getNodes() override;
protected:
	ProjectHierarchy();

private:
	ProjectHierarchyPtr sharedFromThis();

	std::vector<HierarchyNodePtr> children;
};

#endif //MODEL_PROJECTHIERARCHY_H