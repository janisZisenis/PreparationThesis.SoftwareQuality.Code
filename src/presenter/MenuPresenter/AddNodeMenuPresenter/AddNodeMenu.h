#ifndef PRESENTER_ADDNODEMENU_H
#define PRESENTER_ADDNODEMENU_H

#include <presenter/presenter_Export.h>
#include <memory>
#include <string>

class presenter_EXPORT AddNodeMenu {
public:
    virtual void addEntry(std::string entry) = 0;
};

#endif //PRESENTER_ADDNODEMENU_H