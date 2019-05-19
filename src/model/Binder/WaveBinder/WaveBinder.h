#ifndef MODEL_WAVEBINDER_H
#define MODEL_WAVEBINDER_H

#include <model/model_Export.h>
#include <utilities/Visitor/Visitor.h>
#include <utilities/Object/Object.h>

#include "model/HierarchyNode/WaveDynamic/WaveDynamicVisitor.h"

class Wave;

class WaveBinder;
typedef std::shared_ptr<WaveBinder> WaveBinderPtr;

class model_EXPORT WaveBinder : public Visitor, public Object,
	public WaveDynamicVisitor {
public:
	static WaveBinderPtr getNewInstance(std::shared_ptr<Wave> node);
	virtual ~WaveBinder();
protected:
	WaveBinder(std::shared_ptr<Wave> node);
public:
	virtual void visit(std::shared_ptr<WaveDynamic> waveDynamic) override;
private:
	std::shared_ptr<Wave> child;
	bool alreadyVisited = false;
};

#endif //MODEL_WAVEBINDER_H