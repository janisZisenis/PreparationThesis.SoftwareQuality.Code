#ifndef MODEL_SEDIMENTVISITORMOCKS_H
#define MODEL_SEDIMENTVISITORMOCKS_H

#include "SedimentVisitor.h"
#include "model/Visitor/Visitor.h"

class SedimentVisitorDummy;
typedef shared_ptr<SedimentVisitorDummy> SedimentVisitorDummyPtr;
class SedimentVisitorDummy : public SedimentVisitor, public Visitor
{
public:
	static SedimentVisitorDummyPtr getNewInstance()
	{
		return SedimentVisitorDummyPtr(new SedimentVisitorDummy());
	}
	virtual ~SedimentVisitorDummy() {}
protected:
	SedimentVisitorDummy(){}

public:
	virtual void visit(shared_ptr<Sediment> sediment) override {}
};

class SedimentVisitorSpy;
typedef shared_ptr<SedimentVisitorSpy> SedimentVisitorSpyPtr;
class SedimentVisitorSpy : public SedimentVisitorDummy
{
public:
	static SedimentVisitorSpyPtr getNewInstance()
	{
		return SedimentVisitorSpyPtr(new SedimentVisitorSpy());
	}
	virtual ~SedimentVisitorSpy() {}
protected:
	SedimentVisitorSpy() {}

public:
	virtual void visit(shared_ptr<Sediment> sediment) override
	{
		this->iWasTriggeredToVisit = true;
		this->visitedSediment = sediment;
	}
	virtual bool wasTriggeredToVisit()
	{
		return this->iWasTriggeredToVisit;
	}
	virtual shared_ptr<Sediment> getVisitedCoordinateSystem()
	{
		return this->visitedSediment;
	}
private:
	shared_ptr<Sediment> visitedSediment;
	bool iWasTriggeredToVisit = false;
};

#endif //MODEL_SEDIMENTVISITORMOCKS_H