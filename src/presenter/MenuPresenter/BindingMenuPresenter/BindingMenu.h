#ifndef PRESENTER_BINDINGMENU_H
#define PRESENTER_BINDINGMENU_H

#include <presenter/presenter_Export.h>
#include <string>

class presenter_EXPORT BindingMenu {
public:
    virtual void clearEntries() = 0;
    virtual void addEntry(std::string entry) = 0;
    virtual void disableMenu() = 0;
    virtual void enableMenu() = 0;
    virtual bool containsEntries() = 0;
};

#endif //PRESENTER_BINDINGMENU_H