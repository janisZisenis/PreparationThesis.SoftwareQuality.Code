#ifndef MODEL_ADDREMOVENODESERVICE_H
#define MODEL_ADDREMOVENODESERVICE_H

#include <memory>

class HierarchyNode;

class AddRemoveNodeService;
typedef std::shared_ptr<AddRemoveNodeService> AddRemoveNodeServicePtr;

class AddRemoveNodeService {
public:
	virtual ~AddRemoveNodeService() {};
protected:
	AddRemoveNodeService() {};

public:
	virtual void addChild(std::shared_ptr<HierarchyNode> node) = 0;
	virtual void removeChild(std::shared_ptr<HierarchyNode> node) = 0;
};

#endif //MODEL_ADDREMOVENODESERVICE_H