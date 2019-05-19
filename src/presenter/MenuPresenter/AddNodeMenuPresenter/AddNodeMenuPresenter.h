#ifndef PRESENTER_ADDNODEMENUPRESENTER_H
#define PRESENTER_ADDNODEMENUPRESENTER_H

#include <presenter/presenter_Export.h>
#include <memory>
#include <string>
#include <vector>

class AddRemoveNodeService;
class HierarchyNodeFactory;
class AddCommandService;
class HierarchyNode;
class AddNodeMenu;
class Command;

class AddNodeMenuPresenter;
typedef std::shared_ptr<AddNodeMenuPresenter> AddNodeMenuPresenterPtr;

class presenter_EXPORT AddNodeMenuPresenter {
public:
    static AddNodeMenuPresenterPtr getNewInstance(AddNodeMenu *addNodeMenu,
                                                  std::shared_ptr<AddCommandService> commandService,
                                                  std::shared_ptr<AddRemoveNodeService> nodeService,
                                                  std::shared_ptr<HierarchyNodeFactory> nodeFactory);

    virtual ~AddNodeMenuPresenter();

protected:
    AddNodeMenuPresenter(AddNodeMenu *addNodeMenu, std::shared_ptr<AddCommandService> commandService,
                             std::shared_ptr<AddRemoveNodeService> nodeService,
                             std::shared_ptr<HierarchyNodeFactory> nodeFactory);

public:
    virtual void onEntryClicked(std::string entry);

private:
    virtual std::shared_ptr<Command> makeAddNodeCommand(std::shared_ptr<HierarchyNode> node);
    virtual void addEntriesToMenu();

    AddNodeMenu *addNodeMenu;
    std::shared_ptr<AddCommandService> commandService;
    std::shared_ptr<AddRemoveNodeService> nodeService;
    std::shared_ptr<HierarchyNodeFactory> nodeFactory;
};

#endif //PRESENTER_ADDNODEMENUPRESENTER_H