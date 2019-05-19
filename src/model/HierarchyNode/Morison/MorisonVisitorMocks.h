#ifndef MODEL_MORISONVISITORMOCKS_H
#define MODEL_MORISONVISITORMOCKS_H

#include "MorisonVisitor.h"
#include "model/Visitor/Visitor.h"

class MorisonVisitorDummy;
typedef shared_ptr<MorisonVisitorDummy> MorisonVisitorDummyPtr;
class MorisonVisitorDummy : public MorisonVisitor, public Visitor
{
public:
	static MorisonVisitorDummyPtr getNewInstance()
	{
		return MorisonVisitorDummyPtr(new MorisonVisitorDummy());
	}
	virtual ~MorisonVisitorDummy() {}
protected:
	MorisonVisitorDummy() {};

public:
	virtual void visit(shared_ptr<Morison> morison) override {}
};

class MorisonVisitorSpy;
typedef shared_ptr<MorisonVisitorSpy> MorisonVisitorSpyPtr;
class MorisonVisitorSpy : public MorisonVisitorDummy
{
public:
	static MorisonVisitorSpyPtr getNewInstance()
	{
		return MorisonVisitorSpyPtr(new MorisonVisitorSpy());
	}
	virtual ~MorisonVisitorSpy() {}
protected:
	MorisonVisitorSpy() {}

public:
	virtual void visit(shared_ptr<Morison> morison) override
	{
		this->iWasTriggeredToVisit = true;
		this->visitedMorison = morison;
	}
	virtual bool wasTriggeredToVisit()
	{
		return this->iWasTriggeredToVisit;
	}
	virtual shared_ptr<Morison> getVisitedMorison()
	{
		return this->visitedMorison;
	}
private:
	shared_ptr<Morison> visitedMorison;
	bool iWasTriggeredToVisit = false;
};

#endif //MODEL_MORISONVISITORMOCKS_H