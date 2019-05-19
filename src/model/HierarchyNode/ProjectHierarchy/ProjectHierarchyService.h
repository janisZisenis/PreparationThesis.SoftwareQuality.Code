#ifndef MODEL_RPOJECTHIERARCHIESERVICE_H
#define MODEL_RPOJECTHIERARCHIESERVICE_H

#include <memory>
#include <vector>

class HierarchyNode;

class ProjectHierarchyService;
typedef std::shared_ptr<ProjectHierarchyService> ProjectHierarchyServicePtr;

class ProjectHierarchyService {
public:
	virtual ~ProjectHierarchyService() {};
protected:
	ProjectHierarchyService() {};

public:
	virtual std::vector<std::shared_ptr<HierarchyNode> > getNodes() = 0;
};

#endif //MODEL_RPOJECTHIERARCHIESERVICE_H