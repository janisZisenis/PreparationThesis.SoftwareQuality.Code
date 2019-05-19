#ifndef PRESENTER_EDITMENUPRESENTER_H
#define PRESENTER_EDITMENUPRESENTER_H

#include <utilities/Observer/Observer.h>
#include <presenter/presenter_Export.h>
#include <memory>

class EditMenu;
class CommandQueue;

class EditMenuPresenter;
typedef std::shared_ptr<EditMenuPresenter> EditMenuPresenterPtr;

class presenter_EXPORT EditMenuPresenter : public Observer {
public:
    static EditMenuPresenterPtr getNewInstance(EditMenu *editMenu, std::shared_ptr<CommandQueue> commandQueue);
    virtual ~EditMenuPresenter();
protected:
    EditMenuPresenter(EditMenu *editMenu, std::shared_ptr<CommandQueue> commandQueue);

public:
    virtual void update();

    virtual void onUndoClick();
    virtual void onRedoClick();
private:

    EditMenu* editMenu;
    std::shared_ptr<CommandQueue> commandQueue;
};

#endif //PRESENTER_EDITMENUPRESENTER_H