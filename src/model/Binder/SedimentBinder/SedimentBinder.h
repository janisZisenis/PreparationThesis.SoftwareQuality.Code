#ifndef MODEL_SEDIMENTBINDER_H
#define MODEL_SEDIMENTBINDER_H

#include <model/model_Export.h>
#include <utilities/Visitor/Visitor.h>
#include <utilities/Object/Object.h>

#include "model/HierarchyNode/SedimentTransport/SedimentTransportVisitor.h"

class Sediment;

class SedimentBinder;
typedef std::shared_ptr<SedimentBinder> SedimentBinderPtr;

class model_EXPORT SedimentBinder : public Visitor, public Object,
	public SedimentTransportVisitor {
public:
	static SedimentBinderPtr getNewInstance(std::shared_ptr<Sediment> node);
	virtual ~SedimentBinder();
protected:
	SedimentBinder(std::shared_ptr<Sediment> node);
public:
	virtual void visit(std::shared_ptr<SedimentTransport> sedimentTransport) override;
private:
	std::shared_ptr<Sediment> child;
	bool alreadyVisited = false;
};

#endif //MODEL_SEDIMENTBINDER_H