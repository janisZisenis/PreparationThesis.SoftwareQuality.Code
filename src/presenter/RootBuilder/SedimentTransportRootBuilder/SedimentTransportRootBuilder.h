#ifndef PRESENTER_SEDIMENTTRANSPORTROOTBUILDER_H
#define PRESENTER_SEDIMENTTRANSPORTROOTBUILDER_H

#include <presenter/RootBuilder/RootBuilder.h>

class SedimentTransport;

class SedimentTransportRootBuilder;
typedef std::shared_ptr<SedimentTransportRootBuilder> SedimentTransportRootBuilderPtr;
class presenter_EXPORT SedimentTransportRootBuilder : public RootBuilder {
public:
    static SedimentTransportRootBuilderPtr getNewInstance(std::shared_ptr<SedimentTransport> node);
    virtual ~SedimentTransportRootBuilder();
protected:
    SedimentTransportRootBuilder(std::shared_ptr<SedimentTransport> node);

public:
    virtual std::shared_ptr<TableItem> buildRoot();

private:
    std::shared_ptr<SedimentTransport> node;
};

#endif //PRESENTER_SEDIMENTTRANSPORTROOTBUILDER_H