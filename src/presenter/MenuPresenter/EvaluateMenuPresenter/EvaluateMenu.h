#ifndef PRESENTER_EVALUATEMENU_H
#define PRESENTER_EVALUATEMENU_H

#include <presenter/presenter_Export.h>
#include <string>

class presenter_EXPORT EvaluateMenu {
public:
    virtual void clearEntries() = 0;
    virtual void addEntry(std::string entry) = 0;
    virtual void disableMenu() = 0;
    virtual void enableMenu() = 0;
    virtual bool containsEntries() = 0;
};

#endif //PRESENTER_EVALUATEMENU_H