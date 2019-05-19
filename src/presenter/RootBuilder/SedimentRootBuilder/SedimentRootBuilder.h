#ifndef PRESENTER_SEDIMENTROOTBUILDER_H
#define PRESENTER_SEDIMENTROOTBUILDER_H

#include <presenter/RootBuilder/RootBuilder.h>

class Sediment;

class SedimentRootBuilder;
typedef std::shared_ptr<SedimentRootBuilder> SedimentRootBuilderPtr;
class presenter_EXPORT SedimentRootBuilder : public RootBuilder {
public:
    static SedimentRootBuilderPtr getNewInstance(std::shared_ptr<Sediment> node);
    virtual ~SedimentRootBuilder();
protected:
    SedimentRootBuilder(std::shared_ptr<Sediment> node);

public:
    virtual std::shared_ptr<TableItem> buildRoot();

private:
    std::shared_ptr<Sediment> node;
};

#endif //PRESENTER_SEDIMENTROOTBUILDER_H