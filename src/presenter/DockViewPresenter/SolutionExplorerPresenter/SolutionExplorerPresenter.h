#ifndef PRESENTER_SOLUTIONEXPLORERPRESENTER_H
#define PRESENTER_SOLUTIONEXPLORERPRESENTER_H

#include <memory>
#include <presenter/presenter_Export.h>
#include <utilities/Observer/Subject.h>
#include "SelectedNodeAccess.h"

class Editor;
class Command;
class HierarchyNode;
class SolutionExplorer;
class AddCommandService;

class SolutionExplorerPresenter;
typedef std::shared_ptr<SolutionExplorerPresenter> SolutionExplorerPresenterPtr;
class presenter_EXPORT SolutionExplorerPresenter : public Subject, public SelectedNodeAccess {
public:
    static SolutionExplorerPresenterPtr getNewInstance(SolutionExplorer *view, std::shared_ptr<AddCommandService> commandService);
    virtual ~SolutionExplorerPresenter();
protected:
    SolutionExplorerPresenter(SolutionExplorer *view, std::shared_ptr<AddCommandService> commandService);

public:
    virtual void onVisibilityChanged();
    virtual void onSelectionChanged();
    virtual void onItemEdited(std::string newName);

    virtual std::shared_ptr<HierarchyNode> getSelectedNode();

protected:
    virtual std::shared_ptr<Command> makeEditNameCommand(std::shared_ptr<Editor> editor, std::string name);
private:
    SolutionExplorer *view;
    std::shared_ptr<HierarchyNode> selectedNode;
    std::shared_ptr<AddCommandService> commandService;
};


#endif //PRESENTER_SOLUTIONEXPLORERPRESENTER_H