#ifndef PRESENTER_VIEW_H
#define PRESENTER_VIEW_H

#include <presenter/presenter_Export.h>
#include <string>

class presenter_EXPORT View {
public:
    virtual std::string getTitle() = 0;
    virtual bool isVisible() = 0;
    virtual void changeVisibility() = 0;
};

#endif //PRESENTER_VIEW_H