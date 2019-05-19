#ifndef PRESENTER_SHELL_H
#define PRESENTER_SHELL_H

#include <presenter/presenter_Export.h>
#include <memory>

class View;
class Menu;

class presenter_EXPORT Shell {
public:
    virtual void addEvalutationView(View *view) = 0;
    virtual void addInspectorView(View *view) = 0;
};

#endif //PRESENTER_SHELL_H