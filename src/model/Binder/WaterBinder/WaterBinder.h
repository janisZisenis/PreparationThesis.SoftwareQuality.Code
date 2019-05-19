#ifndef MODEL_WATERBINDER_H
#define MODEL_WATERBINDER_H

#include <model/model_Export.h>
#include <utilities/Visitor/Visitor.h>
#include <utilities/Object/Object.h>

#include "model/HierarchyNode/Morison/MorisonVisitor.h"
#include "model/HierarchyNode/SedimentTransport/SedimentTransportVisitor.h"

class Water;

class WaterBinder;
typedef std::shared_ptr<WaterBinder> WaterBinderPtr;

class model_EXPORT WaterBinder : public Visitor, public Object,
	public MorisonVisitor,
	public SedimentTransportVisitor {
public:
	static WaterBinderPtr getNewInstance(std::shared_ptr<Water> node);
	virtual ~WaterBinder();
protected:
	WaterBinder(std::shared_ptr<Water> node);

public:
	virtual void visit(std::shared_ptr<Morison> morison) override;
	virtual void visit(std::shared_ptr<SedimentTransport> sedimentTransport) override;
private:
	std::shared_ptr<Water> child;
	bool alreadyVisited = false;
};

#endif //MODEL_WATERBINDER_H