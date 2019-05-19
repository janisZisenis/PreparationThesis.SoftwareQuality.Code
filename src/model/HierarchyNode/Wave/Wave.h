#ifndef MODEL_WAVE_H
#define MODEL_WAVE_H

#include "model/HierarchyNode/HierarchyNode.h"

class Wave;
typedef std::shared_ptr<Wave> WavePtr;

class model_EXPORT Wave : public HierarchyNode {
public:
	static WavePtr getNewInstance();
	virtual ~Wave();
protected:
	Wave();

public:
	virtual void setLength(double length);
	virtual double getLength();

	virtual void setPeriod(double period);
	virtual double getPeriod();

	virtual void setHeight(double height);
	virtual double getHeight();

	virtual void setWaterDepth(double waterDepth);
	virtual double getWaterDepth();

	virtual double getAngularFrequency();
	virtual double getAngularNumber();

	virtual std::shared_ptr<Visitor> makeBinder() override;
	virtual std::shared_ptr<Editor> makeEditor() override;
	virtual void accept(std::shared_ptr<Visitor> visitor) override;
private:
	WavePtr sharedFromThis();

	static int timesInstantiated;

	double length = 0;
	double period = 0;
	double height = 0;
	double waterDepth = 0;

};

#endif //MODEL_WAVE_H