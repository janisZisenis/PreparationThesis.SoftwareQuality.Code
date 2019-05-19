#ifndef MODEL_PILEVISITORMOCKS_H
#define MODEL_PILEVISITORMOCKS_H

#include "PileVisitor.h"
#include "model/Visitor/Visitor.h"

class PileVisitorDummy;
typedef shared_ptr<PileVisitorDummy> PileVisitorDummyPtr;
class PileVisitorDummy : public PileVisitor, public Visitor
{
public:
	static PileVisitorDummyPtr getNewInstance()
	{
		return PileVisitorDummyPtr(new PileVisitorDummy());
	}
	virtual ~PileVisitorDummy() {}
protected:
	PileVisitorDummy() {};

public:
	virtual void visit(shared_ptr<Pile> pile) override {}
};

class PileVisitorSpy;
typedef shared_ptr<PileVisitorSpy> PileVisitorSpyPtr;
class PileVisitorSpy : public PileVisitorDummy
{
public:
	static PileVisitorSpyPtr getNewInstance()
	{
		return PileVisitorSpyPtr(new PileVisitorSpy());
	}
	virtual ~PileVisitorSpy() {}
protected:
	PileVisitorSpy() {}

public:
	virtual void visit(shared_ptr<Pile> pile) override
	{
		this->iWasTriggeredToVisit = true;
		this->visitedPile = pile;
	}
	virtual bool wasTriggeredToVisit()
	{
		return this->iWasTriggeredToVisit;
	}
	virtual shared_ptr<Pile> getVisitedPile()
	{
		return this->visitedPile;
	}
private:
	shared_ptr<Pile> visitedPile;
	bool iWasTriggeredToVisit = false;
};

#endif //MODEL_PILEVISITORMOCKS_H