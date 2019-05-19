#ifndef PRESENTER_WATERROOTBUILDER_H
#define PRESENTER_WATERROOTBUILDER_H

#include <presenter/RootBuilder/RootBuilder.h>

class Water;

class WaterRootBuilder;
typedef std::shared_ptr<WaterRootBuilder> WaterRootBuilderPtr;
class presenter_EXPORT WaterRootBuilder : public RootBuilder {
public:
    static WaterRootBuilderPtr getNewInstance(std::shared_ptr<Water> node);
    virtual ~WaterRootBuilder();
protected:
    WaterRootBuilder(std::shared_ptr<Water> node);

public:
    virtual std::shared_ptr<TableItem> buildRoot();

private:
    std::shared_ptr<Water> node;
};

#endif //PRESENTER_WATERROOTBUILDER_H