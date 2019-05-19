#ifndef MODEL_WAVEVISITORMOCKS_H
#define MODEL_WAVEVISITORMOCKS_H

#include "WaveVisitor.h"
#include "model/Visitor/Visitor.h"

class WaveVisitorDummy;
typedef shared_ptr<WaveVisitorDummy> WaveVisitorDummyPtr;
class WaveVisitorDummy : public WaveVisitor, public Visitor
{
public:
	static WaveVisitorDummyPtr getNewInstance()
	{
		return WaveVisitorDummyPtr(new WaveVisitorDummy());
	}
	virtual ~WaveVisitorDummy() {}
protected:
	WaveVisitorDummy() {};

public:
	virtual void visit(shared_ptr<Wave> wave) override {}

};

class WaveVisitorSpy;
typedef shared_ptr<WaveVisitorSpy> WaveVisitorSpyPtr;
class WaveVisitorSpy : public WaveVisitorDummy
{
public:
	static WaveVisitorSpyPtr getNewInstance()
	{
		return WaveVisitorSpyPtr(new WaveVisitorSpy());
	}
	virtual ~WaveVisitorSpy() {}
protected:
	WaveVisitorSpy() {}

public:
	virtual void visit(shared_ptr<Wave> wave) override
	{
		this->iWasTriggeredToVisit = true;
		this->visitedWave = wave;
	}
	virtual bool wasTriggeredToVisit()
	{
		return this->iWasTriggeredToVisit;
	}
	virtual shared_ptr<Wave> getVisitedWave()
	{
		return this->visitedWave;
	}
private:
	shared_ptr<Wave> visitedWave;
	bool iWasTriggeredToVisit = false;
};

#endif //MODEL_WAVEVISITORMOCKS_H