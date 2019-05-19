#ifndef MODEL_PILEMOCKS_H
#define MODEL_PILEMOCKS_H

#include "Pile.h"

class PileSubClass;
typedef shared_ptr<PileSubClass> PileSubClassPtr;
class PileSubClass : public Pile
{
public:
	static PileSubClassPtr getNewInstance()
	{
		return PileSubClassPtr(new PileSubClass());
	}
	virtual ~PileSubClass() {}
protected:
	PileSubClass() : Pile() {}
};

class PileSubClassPropertiesStub;
typedef shared_ptr<PileSubClassPropertiesStub> PileSubClassPropertiesStubPtr;
class PileSubClassPropertiesStub : public PileSubClass
{
public:
	static PileSubClassPropertiesStubPtr getNewInstance()
	{
		return PileSubClassPropertiesStubPtr(new PileSubClassPropertiesStub());
	};
	virtual ~PileSubClassPropertiesStub() {};
protected:
	PileSubClassPropertiesStub() : PileSubClass() {};

public:
	virtual void setProperties(string name)
	{
		this->stubName = name;
	}

	virtual string getName() override
	{
		return stubName;
	}
private:
	string stubName;
};

#endif //MODEL_PILEMOCKS_H