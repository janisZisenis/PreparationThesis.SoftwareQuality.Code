#ifndef MODEL_WAVEDYNAMICBINDER_H
#define MODEL_WAVEDYNAMICBINDER_H

#include <model/model_Export.h>
#include <utilities/Visitor/Visitor.h>
#include <utilities/Object/Object.h>

#include "model/HierarchyNode/Morison/MorisonVisitor.h"
#include "model/HierarchyNode/SedimentTransport/SedimentTransportVisitor.h"

class WaveDynamic;

class WaveDynamicBinder;
typedef std::shared_ptr<WaveDynamicBinder> WaveDynamicBinderPtr;

class model_EXPORT WaveDynamicBinder : public Visitor, public Object,
	public MorisonVisitor,
	public SedimentTransportVisitor {
public:
	static WaveDynamicBinderPtr getNewInstance(std::shared_ptr<WaveDynamic> node);
	virtual ~WaveDynamicBinder();
protected:
	WaveDynamicBinder(std::shared_ptr<WaveDynamic> node);
public:
	virtual void visit(std::shared_ptr<Morison> morison) override;
	virtual void visit(std::shared_ptr<SedimentTransport> sedimentTransport) override;
private:
	std::shared_ptr <WaveDynamic> child;
	bool alreadyVisited = false;
};

#endif //MODEL_WAVEDYNAMICBINDER_H