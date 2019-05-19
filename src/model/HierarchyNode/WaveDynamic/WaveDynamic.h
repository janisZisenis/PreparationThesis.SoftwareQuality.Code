#ifndef MODEL_WAVEDYNAMIC_H
#define MODEL_WAVEDYNAMIC_H

#include <model/model_Export.h>
#include "model/HierarchyNode/HierarchyNode.h"

class CoordinateSystem;
class Water;
class Wave;

class WaveDynamic;
typedef std::shared_ptr<WaveDynamic> WaveDynamicPtr;

class model_EXPORT WaveDynamic : public HierarchyNode {
public:
	static WaveDynamicPtr getNewInstance();
	virtual ~WaveDynamic();

protected:
	WaveDynamic();

public:
    virtual bool canBind(HierarchyNodePtr node) override;

	virtual void setCoordinateSystem(std::shared_ptr<CoordinateSystem> coordinateSystem);
	virtual std::shared_ptr<CoordinateSystem> getCoordinateSystem();
	virtual void setWave(std::shared_ptr<Wave> wave);
	virtual std::shared_ptr<Wave> getWave();

	virtual std::shared_ptr<Visitor> makeBinder() override;
	virtual std::shared_ptr<Editor> makeEditor() override;
	virtual void accept(std::shared_ptr<Visitor> visitor) override;

	virtual double getAngularWaveNumber();
	virtual double getAngularWaveFrequency();
	virtual double getWaveLength();
	virtual double getWavePeriod();
	virtual double getWaveHeight();
	virtual double getWaterDepth();

	virtual double getWaterSurfaceDisplacement();
	virtual double getSpatialWaterProfile(double x);
	virtual double getTimeWaterProfile(double t);

private:
	virtual double calcWaveProfile(double waveHeight, double k, double  omega, double x, double t);

	WaveDynamicPtr sharedFromThis();

	static int timesInstantiated;

	std::shared_ptr<CoordinateSystem> coordinateSystem;
	std::shared_ptr<Wave> wave;
};

#endif //MODEL_WAVEDYNAMIC_H