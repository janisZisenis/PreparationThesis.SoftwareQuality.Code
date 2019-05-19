#ifndef MODEL_COORDINATESYSTEMMOCKS_H
#define MODEL_COORDINATESYSTEMMOCKS_H

#include "CoordinateSystem.h"

class CoordinateSystemSubClass;
typedef shared_ptr<CoordinateSystemSubClass> CoordinateSystemSubClassPtr;
class CoordinateSystemSubClass : public CoordinateSystem
{
public:
	static CoordinateSystemSubClassPtr getNewInstance()
	{
		return CoordinateSystemSubClassPtr(new CoordinateSystemSubClass());
	}
	virtual ~CoordinateSystemSubClass() {}
protected:
	CoordinateSystemSubClass() : CoordinateSystem(){}
public:
};

class CoordinateSystemSubClassPropertiesStub;
typedef shared_ptr<CoordinateSystemSubClassPropertiesStub> CoordinateSystemSubClassPropertiesStubPtr;
class CoordinateSystemSubClassPropertiesStub : public CoordinateSystemSubClass
{
public:
	static CoordinateSystemSubClassPropertiesStubPtr getNewInstance()
	{
		return CoordinateSystemSubClassPropertiesStubPtr(new CoordinateSystemSubClassPropertiesStub());
	};
	virtual ~CoordinateSystemSubClassPropertiesStub() {};
protected:
	CoordinateSystemSubClassPropertiesStub() : CoordinateSystemSubClass() {};

public:
	virtual void setProperties(string name, double x, double t, double z)
	{
		stubName = name;
		stubX = x;
		stubT = t;
		stubZ = z;
	}
	virtual string getName() override
	{
		return stubName;
	}
	virtual double getX() override
	{
		return stubX;
	}
	virtual double getT() override
	{
		return stubT;
	}
	virtual double getZ() override
	{
		return stubZ;
	}

private:
	string stubName;
	double stubX;
	double stubT;
	double stubZ;
};

#endif //MODEL_COORDINATESYSTEMMOCKS_H