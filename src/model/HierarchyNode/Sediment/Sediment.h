#ifndef MODEL_SEDIMENT_H
#define MODEL_SEDIMENT_H

#include "model/HierarchyNode/HierarchyNode.h"

class Sediment;
typedef std::shared_ptr<Sediment> SedimentPtr;

class model_EXPORT Sediment : public HierarchyNode {
public:
	static SedimentPtr getNewInstance();
	virtual ~Sediment();
protected:
	Sediment();

public:
	virtual void setDensity(double density);
	virtual double getDensity();

	virtual std::shared_ptr<Visitor> makeBinder() override;
	virtual std::shared_ptr<Editor> makeEditor() override;
	virtual void accept(std::shared_ptr<Visitor> visitor) override;
private:
	SedimentPtr sharedFromThis();

	static int timesInstantiated;

	double density = 0;
};

#endif //MODEL_SEDIMENT_H