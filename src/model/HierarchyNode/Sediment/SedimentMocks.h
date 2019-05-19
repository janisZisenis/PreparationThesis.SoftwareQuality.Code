#ifndef MODEL_SEDIMENTMOCKS_H
#define MODEL_SEDIMENTMOCKS_H

#include "Sediment.h"

class SedimentSubClass;
typedef shared_ptr<SedimentSubClass> SedimentSubClassPtr;
class SedimentSubClass : public Sediment
{
public:
	static SedimentSubClassPtr getNewInstance()
	{
		return SedimentSubClassPtr(new SedimentSubClass());
	}
	virtual ~SedimentSubClass() {}
protected:
	SedimentSubClass(): Sediment() {}
};

class SedimentSubClassPropertiesStub;
typedef shared_ptr<SedimentSubClassPropertiesStub> SedimentSubClassPropertiesStubPtr;
class SedimentSubClassPropertiesStub : public SedimentSubClass
{
public:
	static SedimentSubClassPropertiesStubPtr getNewInstance()
	{
		return SedimentSubClassPropertiesStubPtr(new SedimentSubClassPropertiesStub());
	};
	virtual ~SedimentSubClassPropertiesStub() {};
protected:
	SedimentSubClassPropertiesStub() : SedimentSubClass() {};

public:
	virtual void setProperties(string name)
	{
		stubName = name;
	}

	virtual string getName() override
	{
		return this->stubName;
	}

private:
	string stubName;
};

#endif //MODEL_SEDIMENTMOCKS_H