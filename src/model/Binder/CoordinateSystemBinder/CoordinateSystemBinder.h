#ifndef MODEL_COORDINATESYSTEMBINDER_H
#define MODEL_COORDINATESYSTEMBINDER_H

#include <model/model_Export.h>
#include <utilities/Visitor/Visitor.h>
#include <utilities/Object/Object.h>

#include "model/HierarchyNode/WaveDynamic/WaveDynamicVisitor.h"

class CoordinateSystem;

class CoordinateSystemBinder;
typedef std::shared_ptr<CoordinateSystemBinder> CoordinateSystemBinderPtr;

class model_EXPORT CoordinateSystemBinder : public Visitor, public Object,
	public WaveDynamicVisitor {
public:
	static CoordinateSystemBinderPtr getNewInstance(std::shared_ptr<CoordinateSystem> node);
	virtual ~CoordinateSystemBinder();
protected:
	CoordinateSystemBinder(std::shared_ptr<CoordinateSystem> node);

public:
	virtual void visit(std::shared_ptr<WaveDynamic> waveDynamic) override;
private:
	std::shared_ptr<CoordinateSystem> child;
	bool alreadyVisited = false;
};

#endif //MODEL_COORDINATESYSTEMBINDER_H