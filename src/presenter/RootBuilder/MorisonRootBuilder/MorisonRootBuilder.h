#ifndef PRESENTER_MORISONROOTBUILDER_H
#define PRESENTER_MORISONROOTBUILDER_H

#include <presenter/RootBuilder/RootBuilder.h>

class Morison;

class MorisonRootBuilder;
typedef std::shared_ptr<MorisonRootBuilder> MorisonRootBuilderPtr;
class presenter_EXPORT MorisonRootBuilder : public RootBuilder {
public:
    static MorisonRootBuilderPtr getNewInstance(std::shared_ptr<Morison> node);
    virtual ~MorisonRootBuilder();
protected:
    MorisonRootBuilder(std::shared_ptr<Morison> node);

public:
    virtual std::shared_ptr<TableItem> buildRoot();

private:
    std::shared_ptr<Morison> node;
};

#endif //PRESENTER_MORISONROOTBUILDER_H