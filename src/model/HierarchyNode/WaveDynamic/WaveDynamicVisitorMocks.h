#ifndef MODEL_WAVEDYNAMICVISITORMOCKS_H
#define MODEL_WAVEDYNAMICVISITORMOCKS_H

#include "WaveDynamicVisitor.h"
#include "model/Visitor/Visitor.h"

class WaveDynamicVisitorDummy;
typedef shared_ptr<WaveDynamicVisitorDummy> WaveDynamicVisitorDummyPtr;
class WaveDynamicVisitorDummy : public WaveDynamicVisitor, public Visitor
{
public:
	static WaveDynamicVisitorDummyPtr getNewInstance()
	{
		return WaveDynamicVisitorDummyPtr(new WaveDynamicVisitorDummy());
	}
	virtual ~WaveDynamicVisitorDummy() {}
protected:
	WaveDynamicVisitorDummy() {};

public:
	virtual void visit(shared_ptr<WaveDynamic> waveDynamic) override {}
};

class WaveDynamicVisitorSpy;
typedef shared_ptr<WaveDynamicVisitorSpy> WaveDynamicVisitorSpyPtr;
class WaveDynamicVisitorSpy : public WaveDynamicVisitorDummy
{
public:
	static WaveDynamicVisitorSpyPtr getNewInstance()
	{
		return WaveDynamicVisitorSpyPtr(new WaveDynamicVisitorSpy());
	}
	virtual ~WaveDynamicVisitorSpy() {}
protected:
	WaveDynamicVisitorSpy() {}

public:
	virtual void visit(shared_ptr<WaveDynamic> waveDynamic) override
	{
		this->iWasTriggeredToVisit = true;
		this->visitedWaveDynamic = waveDynamic;
	}
	virtual bool wasTriggeredToVisit()
	{
		return this->iWasTriggeredToVisit;
	}
	virtual shared_ptr<WaveDynamic> getVisitedWaveDynamic()
	{
		return this->visitedWaveDynamic;
	}
private:
	shared_ptr<WaveDynamic> visitedWaveDynamic;
	bool iWasTriggeredToVisit = false;
};

#endif //MODEL_WAVEDYNAMICVISITORMOCKS_H