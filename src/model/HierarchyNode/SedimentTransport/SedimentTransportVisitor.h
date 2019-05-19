#ifndef MODEL_SEDIMENTTRANSPORTVISITOR
#define MODEL_SEDIMENTTRANSPORTVISITOR

#include <memory>

class SedimentTransport;

class SedimentTransportVisitor;
typedef std::shared_ptr<SedimentTransportVisitor> SedimentTransportVisitorPtr;

class SedimentTransportVisitor {
protected:
	SedimentTransportVisitor() {};

public:
	virtual void visit(std::shared_ptr<SedimentTransport> sedimentTransport) = 0;
};

#endif //MODEL_SEDIMENTTRANSPORTVISITOR