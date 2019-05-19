#ifndef PRESENTER_COORDINATESYSTEMROOTBUILDER_H
#define PRESENTER_COORDINATESYSTEMROOTBUILDER_H

#include <presenter/RootBuilder/RootBuilder.h>

class CoordinateSystem;

class CoordinateSystemRootBuilder;
typedef std::shared_ptr<CoordinateSystemRootBuilder> CoordinateSystemRootBuilderPtr;
class presenter_EXPORT CoordinateSystemRootBuilder : public RootBuilder {
public:
    static CoordinateSystemRootBuilderPtr getNewInstance(std::shared_ptr<CoordinateSystem> node);
    virtual ~CoordinateSystemRootBuilder();
protected:
    CoordinateSystemRootBuilder(std::shared_ptr<CoordinateSystem> node);

public:
    virtual std::shared_ptr<TableItem> buildRoot();

private:
    std::shared_ptr<CoordinateSystem> node;
};

#endif //PRESENTER_COORDINATESYSTEMROOTBUILDER_H