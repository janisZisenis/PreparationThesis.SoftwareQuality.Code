#ifndef PRESENTER_WAVEDYNAMICROOTBUILDER_H
#define PRESENTER_WAVEDYNAMICROOTBUILDER_H

#include <presenter/RootBuilder/RootBuilder.h>

class WaveDynamic;

class WaveDynamicRootBuilder;
typedef std::shared_ptr<WaveDynamicRootBuilder> WaveDynamicRootBuilderPtr;
class presenter_EXPORT WaveDynamicRootBuilder : public RootBuilder {
public:
    static WaveDynamicRootBuilderPtr getNewInstance(std::shared_ptr<WaveDynamic> node);
    virtual ~WaveDynamicRootBuilder();
protected:
    WaveDynamicRootBuilder(std::shared_ptr<WaveDynamic> node);

public:
    virtual std::shared_ptr<TableItem> buildRoot();

private:
    std::shared_ptr<WaveDynamic> node;
};

#endif //PRESENTER_WAVEDYNAMICROOTBUILDER_H