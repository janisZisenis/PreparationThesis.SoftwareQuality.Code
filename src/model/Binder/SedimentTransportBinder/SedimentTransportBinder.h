#ifndef MODEL_SEDIMENTTRANSPORTBINDER_H
#define MODEL_SEDIMENTTRANSPORTBINDER_H

#include <model/model_Export.h>
#include <utilities/Visitor/Visitor.h>
#include <utilities/Object/Object.h>

class SedimentTransport;

class SedimentTransportBinder;
typedef std::shared_ptr<SedimentTransportBinder> SedimentTransportBinderPtr;

class model_EXPORT SedimentTransportBinder : public Visitor, public Object {
public:
	static SedimentTransportBinderPtr getNewInstance(std::shared_ptr<SedimentTransport> node);
	virtual ~SedimentTransportBinder();
protected:
	SedimentTransportBinder(std::shared_ptr<SedimentTransport> node);
private:
	std::shared_ptr<SedimentTransport> child;
	bool alreadyVisited = false;
};

#endif //MODEL_SEDIMENTTRANSPORTBINDER_H