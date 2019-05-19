#ifndef MODEL_COORDINATESYSTEM_H
#define MODEL_COORDINATESYSTEM_H

#include "model/HierarchyNode/HierarchyNode.h"

class CoordinateSystem;
typedef std::shared_ptr<CoordinateSystem> CoordinateSystemPtr;

class model_EXPORT CoordinateSystem : public HierarchyNode {
public:
	static CoordinateSystemPtr getNewInstance();
	virtual ~CoordinateSystem();
protected:
	CoordinateSystem();

public:
	virtual void setX(double x);
	virtual double getX();

	virtual void setT(double t);
	virtual double getT();

	virtual void setZ(double z);
	virtual double getZ();

	virtual std::shared_ptr<Visitor> makeBinder() override;
	virtual std::shared_ptr<Editor> makeEditor() override;
	virtual void accept(std::shared_ptr<Visitor> visitor) override;
private:
	CoordinateSystemPtr sharedFromThis();

	static int timesInstantiated;

	double x = 0;
	double t = 0;
	double z = 0;
};

#endif //MODEL_COORDINATESYSTEM_H