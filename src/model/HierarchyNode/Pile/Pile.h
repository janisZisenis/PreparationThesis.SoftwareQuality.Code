#ifndef MODEL_PILE_H
#define MODEL_PILE_H

#include "model/HierarchyNode/HierarchyNode.h"

class Pile;
typedef std::shared_ptr<Pile> PilePtr;

class model_EXPORT Pile : public HierarchyNode {
public:
	static PilePtr getNewInstance();
	virtual ~Pile();
protected:
	Pile();

public:
	virtual void setDiameter(double diameter);
	virtual double getDiameter();

	virtual std::shared_ptr<Visitor> makeBinder() override;
	virtual std::shared_ptr<Editor> makeEditor() override;
	virtual void accept(std::shared_ptr<Visitor> visitor) override;
private:
	PilePtr sharedFromThis();

	static int timesInstantiated;

	double diameter = 0;
};

#endif //MODEL_PILE_H