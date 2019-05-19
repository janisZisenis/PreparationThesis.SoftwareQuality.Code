#ifndef MODEL_SEDIMENTTRANSPORTMOCKS_H
#define MODEL_SEDIMENTTRANSPORTMOCKS_H

#include "SedimentTransport.h"

class SedimentTransportSubClass;
typedef shared_ptr<SedimentTransportSubClass> SedimentTransportSubClassPtr;
class SedimentTransportSubClass : public SedimentTransport
{
public:
	static SedimentTransportSubClassPtr getNewInstance()
	{
		return SedimentTransportSubClassPtr(new SedimentTransportSubClass());
	}
	virtual ~SedimentTransportSubClass() {}
protected:
	SedimentTransportSubClass() : SedimentTransport(){}
};

class SedimentTransportReturnsNullptrForChilds;
typedef shared_ptr<SedimentTransportReturnsNullptrForChilds> SedimentTransportReturnsNullptrForChildsPtr;
class SedimentTransportReturnsNullptrForChilds : public SedimentTransportSubClass
{
public:
	static SedimentTransportReturnsNullptrForChildsPtr getNewInstance()
	{
		return SedimentTransportReturnsNullptrForChildsPtr(new SedimentTransportReturnsNullptrForChilds());
	}
	virtual ~SedimentTransportReturnsNullptrForChilds() {}
protected:
	SedimentTransportReturnsNullptrForChilds() : SedimentTransportSubClass() {}

public:
	virtual HierarchyNodePtr getWaveDynamic() override
	{
		return nullptr;
	}
	virtual HierarchyNodePtr getSediment() override
	{
		return nullptr;
	}
};

#endif //MODEL_SEDIMENTTRANSPORTMOCKS_H