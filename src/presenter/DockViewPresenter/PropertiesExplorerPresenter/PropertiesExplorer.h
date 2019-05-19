#ifndef PRESENTER_PROPERTIESEXPLORER_H
#define PRESENTER_PROPERTIESEXPLORER_H

#include <memory>
#include "presenter/MenuPresenter/ViewMenuPresenter/View.h"

class TableItem;

class PropertiesExplorer : public View {
public:
    virtual ~PropertiesExplorer(){};
protected:
    PropertiesExplorer(){};

public:
    virtual void setTableRoot(std::shared_ptr<TableItem> tableRoot) = 0;
};

#endif //PRESENTER_PROPERTIESEXPLORER_H