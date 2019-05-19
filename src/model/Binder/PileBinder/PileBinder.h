#ifndef MODEL_PILEBINDER_H
#define MODEL_PILEBINDER_H

#include <model/model_Export.h>
#include <utilities/Visitor/Visitor.h>
#include <utilities/Object/Object.h>

#include "model/HierarchyNode/Morison/MorisonVisitor.h"

class Pile;

class PileBinder;
typedef std::shared_ptr<PileBinder> PileBinderPtr;

class model_EXPORT PileBinder : public Visitor, public Object,
	public MorisonVisitor {
public:
	static PileBinderPtr getNewInstance(std::shared_ptr<Pile> node);
	virtual ~PileBinder();
protected:
	PileBinder(std::shared_ptr<Pile> node);
public:
	virtual void visit(std::shared_ptr<Morison> morison) override;
private:
	std::shared_ptr<Pile> child;
	bool alreadyVisited = false;
};

#endif //MODEL_PILEBINDER_H