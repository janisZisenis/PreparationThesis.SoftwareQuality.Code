#ifndef PRESENTER_PILEROOTBUILDER_H
#define PRESENTER_PILEROOTBUILDER_H

#include <presenter/RootBuilder/RootBuilder.h>

class Pile;

class PileRootBuilder;
typedef std::shared_ptr<PileRootBuilder> PileRootBuilderPtr;
class presenter_EXPORT PileRootBuilder : public RootBuilder {
public:
    static PileRootBuilderPtr getNewInstance(std::shared_ptr<Pile> node);
    virtual ~PileRootBuilder();
protected:
    PileRootBuilder(std::shared_ptr<Pile> node);

public:
    virtual std::shared_ptr<TableItem> buildRoot();

private:
    std::shared_ptr<Pile> node;
};

#endif //PRESENTER_PILEROOTBUILDER_H