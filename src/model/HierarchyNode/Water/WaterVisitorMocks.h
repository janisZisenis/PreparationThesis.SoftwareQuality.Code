#ifndef MODEL_WATERVISITORMOCKS_H
#define MODEL_WATERVISITORMOCKS_H

#include "WaterVisitor.h"
#include "model/Visitor/Visitor.h"

class WaterVisitorDummy;
typedef shared_ptr<WaterVisitorDummy> WaterVisitorDummyPtr;
class WaterVisitorDummy : public WaterVisitor, public Visitor
{
public:
	static WaterVisitorDummyPtr getNewInstance()
	{
		return WaterVisitorDummyPtr(new WaterVisitorDummy());
	}
	virtual ~WaterVisitorDummy() {}
protected:
	WaterVisitorDummy() {};

public:
	virtual void visit(shared_ptr<Water> water) override {}
};

class WaterVisitorSpy;
typedef shared_ptr<WaterVisitorSpy> WaterVisitorSpyPtr;
class WaterVisitorSpy : public WaterVisitorDummy
{
public:
	static WaterVisitorSpyPtr getNewInstance()
	{
		return WaterVisitorSpyPtr(new WaterVisitorSpy());
	}
	virtual ~WaterVisitorSpy() {}
protected:
	WaterVisitorSpy() {}

public:
	virtual void visit(shared_ptr<Water> water) override
	{
		this->iWasTriggeredToVisit = true;
		this->visitedWater = water;
	}
	virtual bool wasTriggeredToVisit()
	{
		return this->iWasTriggeredToVisit;
	}
	virtual shared_ptr<Water> getVisitedWater()
	{
		return this->visitedWater;
	}
private:
	shared_ptr<Water> visitedWater;
	bool iWasTriggeredToVisit = false;
};

#endif //MODEL_WATERVISITORMOCKS_H