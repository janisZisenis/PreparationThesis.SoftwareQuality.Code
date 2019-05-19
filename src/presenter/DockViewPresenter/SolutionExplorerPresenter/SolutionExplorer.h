#ifndef PRESENTER_SOLUTIONEXPLORER_H
#define PRESENTER_SOLUTIONEXPLORER_H

#include <memory>
#include "presenter/MenuPresenter/ViewMenuPresenter/View.h"

class TreeItem;

class SolutionExplorer : public View {
public:
    virtual ~SolutionExplorer() {};
protected:
    SolutionExplorer() {};

public:
    virtual TreeItem* getSelectedItem() = 0;
};

#endif //PRESENTER_SOLUTIONEXPLORER_H