#ifndef MODEL_WATER_H
#define MODEL_WATER_H

#include "model/HierarchyNode/HierarchyNode.h"

class Water;
typedef std::shared_ptr<Water> WaterPtr;

class model_EXPORT  Water : public HierarchyNode {
public:
	static WaterPtr getNewInstance();
	virtual ~Water();
protected:
	Water();

public:
	virtual void setDensity(double density);
	virtual double getDensity();

	virtual void setViscosity(double viscosity);
	virtual double getViscosity();

	virtual std::shared_ptr<Visitor> makeBinder() override;
	virtual std::shared_ptr<Editor> makeEditor() override;
	virtual void accept(std::shared_ptr<Visitor> visitor) override;
private:
	WaterPtr sharedFromThis();

	static int timesInstantiated;

	double density = 0;
	double viscosity = 0;
};

#endif //MODEL_WATER_H