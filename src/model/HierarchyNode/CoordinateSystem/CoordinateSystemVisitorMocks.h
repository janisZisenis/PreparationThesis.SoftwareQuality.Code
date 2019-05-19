#ifndef MODEL_COORDINATESYSTEMVISITORMOCKS_H
#define MODEL_COORDINATESYSTEMVISITORMOCKS_H

#include "CoordinateSystemVisitor.h"
#include "model/Visitor/Visitor.h"

class CoordinateSystemVisitorDummy;
typedef shared_ptr<CoordinateSystemVisitorDummy> CoordinateSystemVisitorDummyPtr;
class CoordinateSystemVisitorDummy : public CoordinateSystemVisitor, public Visitor
{
public:
	static CoordinateSystemVisitorDummyPtr getNewInstance()
	{
		return CoordinateSystemVisitorDummyPtr(new CoordinateSystemVisitorDummy());
	}
	virtual ~CoordinateSystemVisitorDummy() {}
protected:
	CoordinateSystemVisitorDummy(){}

public:
	virtual void visit(shared_ptr<CoordinateSystem> coordinateSystem) override {}
};

class CoordinateSystemVisitorSpy;
typedef shared_ptr<CoordinateSystemVisitorSpy> CoordinateSystemVisitorSpyPtr;
class CoordinateSystemVisitorSpy : public CoordinateSystemVisitorDummy
{
public:
	static CoordinateSystemVisitorSpyPtr getNewInstance()
	{
		return CoordinateSystemVisitorSpyPtr(new CoordinateSystemVisitorSpy());
	}
	virtual ~CoordinateSystemVisitorSpy() {}
protected:
	CoordinateSystemVisitorSpy() {}

public:
	virtual void visit(shared_ptr<CoordinateSystem> coordinateSystem) override
	{
		this->iWasTriggeredToVisit = true;
		this->visitedCoordinateSystem = coordinateSystem;
	}
	virtual bool wasTriggeredToVisit()
	{
		return this->iWasTriggeredToVisit;
	}
	virtual shared_ptr<CoordinateSystem> getVisitedCoordinateSystem()
	{
		return this->visitedCoordinateSystem;
	}
private:
	shared_ptr<CoordinateSystem> visitedCoordinateSystem;
	bool iWasTriggeredToVisit = false;
};

#endif //MODEL_COORDINATESYSTEMVISITORMOCKS_H