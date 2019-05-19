#ifndef PRESENTER_BINDINGMENUPRESENTER_H
#define PRESENTER_BINDINGMENUPRESENTER_H

#include <utilities/Observer/Observer.h>
#include <presenter/presenter_Export.h>
#include <memory>
#include <string>

class BindingMenu;
class AddCommandService;
class ProjectHierarchyService;
class Visitor;
class Visitable;
class SelectedNodeAccess;
class Command;


class BindingMenuPresenter;
typedef std::shared_ptr<BindingMenuPresenter> BindingMenuPresenterPtr;

class presenter_EXPORT BindingMenuPresenter : public Observer {
public:
    static BindingMenuPresenterPtr getNewInstance(BindingMenu* bindingMenu,
                                                  std::shared_ptr<AddCommandService> commandService,
                                                  std::shared_ptr<ProjectHierarchyService> projectHierarchyService,
                                                  std::shared_ptr<SelectedNodeAccess> selectedNodeAccess);
    virtual ~BindingMenuPresenter();
protected:
    BindingMenuPresenter(BindingMenu* bindingMenu,
                         std::shared_ptr<AddCommandService> commandService,
                         std::shared_ptr<ProjectHierarchyService> projectHierarchyService,
                         std::shared_ptr<SelectedNodeAccess> selectedNodeAccess);

public:
    virtual void onEntryClicked(std::string entry);
    virtual void update();

protected:
    virtual std::shared_ptr<Command> makeBindingCommand(std::shared_ptr<Visitable> visitable,
                                                        std::shared_ptr<Visitor> visitor);

private:
    BindingMenu* bindingMenu;
    std::shared_ptr<AddCommandService> commandService;
    std::shared_ptr<ProjectHierarchyService> projectHierarchyService;
    std::shared_ptr<SelectedNodeAccess> selectedNodeAccess;
};

#endif //PRESENTER_BINDINGMENUPRESENTER_H