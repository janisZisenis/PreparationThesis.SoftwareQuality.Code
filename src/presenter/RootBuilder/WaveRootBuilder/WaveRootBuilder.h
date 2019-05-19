#ifndef PRESENTER_WAVEROOTBUILDER_H
#define PRESENTER_WAVEROOTBUILDER_H

#include <presenter/RootBuilder/RootBuilder.h>

class Wave;

class WaveRootBuilder;
typedef std::shared_ptr<WaveRootBuilder> WaveRootBuilderPtr;
class presenter_EXPORT WaveRootBuilder : public RootBuilder {
public:
    static WaveRootBuilderPtr getNewInstance(std::shared_ptr<Wave> node);
    virtual ~WaveRootBuilder();
protected:
    WaveRootBuilder(std::shared_ptr<Wave> node);

public:
    virtual std::shared_ptr<TableItem> buildRoot();

private:
    std::shared_ptr<Wave> node;
};

#endif //PRESENTER_WAVEROOTBUILDER_H