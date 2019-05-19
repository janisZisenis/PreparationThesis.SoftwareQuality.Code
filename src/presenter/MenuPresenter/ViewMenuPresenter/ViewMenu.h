#ifndef PRESENTER_VIEWMENU_H
#define PRESENTER_VIEWMENU_H

#include <presenter/presenter_Export.h>
#include <memory>
#include <string>

class presenter_EXPORT ViewMenu
{
public:
    virtual void clearEntries() = 0;
    virtual void addCheckedEntry(std::string entry) = 0;
    virtual void addUncheckedEntry(std::string entry) = 0;
};

#endif //PRESENTER_VIEWMENU_H