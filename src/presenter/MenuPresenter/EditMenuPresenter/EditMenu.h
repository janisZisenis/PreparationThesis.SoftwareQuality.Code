#ifndef PRESENTER_EDITMENU_H
#define PRESENTER_EDITMENU_H

#include <presenter/presenter_Export.h>

class presenter_EXPORT EditMenu {
public:
    virtual void disableUndo() = 0;
    virtual void enableUndo() = 0;
    virtual void disableRedo() = 0;
    virtual void enableRedo() = 0;
};

#endif //PRESENTER_EDITMENU_H