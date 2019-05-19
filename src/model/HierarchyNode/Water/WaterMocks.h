#ifndef MODEL_WATERMOCKS_H
#define MODEL_WATERMOCKS_H

#include "Water.h"

class WaterSubClass;
typedef shared_ptr<WaterSubClass> WaterSubClassPtr;
class WaterSubClass : public Water {
public:
	static WaterSubClassPtr getNewInstance()
	{
		return WaterSubClassPtr(new WaterSubClass());
	}
	virtual ~WaterSubClass() {}
protected:
	WaterSubClass() : Water (){}

public:
};

class WaterSubClassPropertiesStub;
typedef shared_ptr<WaterSubClassPropertiesStub> WaterSubClassPropertiesStubPtr;
class WaterSubClassPropertiesStub : public WaterSubClass
{
public:
	static WaterSubClassPropertiesStubPtr getNewInstance()
	{
		return WaterSubClassPropertiesStubPtr(new WaterSubClassPropertiesStub());
	};
	virtual ~WaterSubClassPropertiesStub() {};
protected:
	WaterSubClassPropertiesStub() : WaterSubClass() {};

public:
	virtual void setProperties(string name, double density, double viscosity)
	{
		stubName = name;
		stubDensity = density;
		stubViscosity = viscosity;
	}
	virtual string getName() override
	{
		return stubName;
	}
	virtual double getDensity() override
	{
		return stubDensity;
	}
	virtual double getViscosity() override
	{
		return stubViscosity;
	}

private:
	string stubName;
	double stubDensity;
	double stubViscosity;
};

#endif //MODEL_WATERMOCKS_H