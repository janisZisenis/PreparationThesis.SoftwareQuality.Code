#ifndef MODEL_SEDIMENTTRANSPORTVISITORMOCKS_H
#define MODEL_SEDIMENTTRANSPORTVISITORMOCKS_H

#include "SedimentTransportVisitor.h"
#include "model/Visitor/Visitor.h"

class SedimentTransportVisitorDummy;
typedef shared_ptr<SedimentTransportVisitorDummy> SedimentTransportVisitorDummyPtr;
class SedimentTransportVisitorDummy : public SedimentTransportVisitor , public Visitor
{
public:
	static SedimentTransportVisitorDummyPtr getNewInstance()
	{
		return SedimentTransportVisitorDummyPtr(new SedimentTransportVisitorDummy());
	}
	virtual ~SedimentTransportVisitorDummy() {}
protected:
	SedimentTransportVisitorDummy() {};

public:
	virtual void visit(shared_ptr<SedimentTransport> sedimentTransport) override {}
};

class SedimentTransportVisitorSpy;
typedef shared_ptr<SedimentTransportVisitorSpy> SedimentTransportVisitorSpyPtr;
class SedimentTransportVisitorSpy : public SedimentTransportVisitorDummy
{
public:
	static SedimentTransportVisitorSpyPtr getNewInstance()
	{
		return SedimentTransportVisitorSpyPtr(new SedimentTransportVisitorSpy());
	}
	virtual ~SedimentTransportVisitorSpy() {}
protected:
	SedimentTransportVisitorSpy() {}

public:
	virtual void visit(shared_ptr<SedimentTransport> sedimentTransport) override
	{
		this->iWasTriggeredToVisit = true;
		this->visitedSedimentTransport = sedimentTransport;
	}
	virtual bool wasTriggeredToVisit()
	{
		return this->iWasTriggeredToVisit;
	}
	virtual shared_ptr<SedimentTransport> getVisitedSedimentTransport()
	{
		return this->visitedSedimentTransport;
	}
private:
	shared_ptr<SedimentTransport> visitedSedimentTransport;
	bool iWasTriggeredToVisit = false;
};

#endif //MODEL_SEDIMENTTRANSPORTVISITORMOCKS_H