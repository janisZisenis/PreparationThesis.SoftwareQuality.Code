#ifndef PRESENTER_PROPERTIESEXPLORERPRESENTER_H
#define PRESENTER_PROPERTIESEXPLORERPRESENTER_H

#include <memory>
#include <string>
#include <presenter/presenter_Export.h>
#include <utilities/Observer/Subject.h>
#include <utilities/Observer/Observer.h>

class PropertiesExplorer;
class RootBuilderFactory;
class SelectedNodeAccess;
class AddCommandService;
class HierarchyNode;
class Editor;
class Command;

class PropertiesExplorerPresenter;
typedef std::shared_ptr<PropertiesExplorerPresenter> PropertiesExplorerPresenterPtr;
class presenter_EXPORT PropertiesExplorerPresenter : public Subject, public Observer {
public:
    static PropertiesExplorerPresenterPtr getNewInstance(PropertiesExplorer *view,
                                                         std::shared_ptr<SelectedNodeAccess> selectedNodeAccess,
                                                         std::shared_ptr<RootBuilderFactory> rootBuilderFactory,
                                                         std::shared_ptr<AddCommandService> commandService);
    virtual ~PropertiesExplorerPresenter();

protected:
    PropertiesExplorerPresenter(PropertiesExplorer *view,
                                std::shared_ptr<SelectedNodeAccess> selectedNodeAccess,
                                std::shared_ptr<RootBuilderFactory> rootBuilderFactory,
                                std::shared_ptr<AddCommandService> commandService);

public:
    virtual void update() override;

    virtual void onVisibilityChanged();
    virtual void onPropertyChanged(std::string propertyName, std::string propertyValue);

protected:
    virtual std::shared_ptr<Command> makeEditCommand(std::shared_ptr<Editor> editor,
                                                       std::string propertyName,
                                                       std::string propertyValue);

private:
    virtual void connectToNewNode(std::shared_ptr<HierarchyNode> newNode);
    virtual void disconnectFromNode();
    virtual void connectToNode(std::shared_ptr<HierarchyNode> node);

    PropertiesExplorer *view;
    std::shared_ptr<RootBuilderFactory> rootBuilderFactory;
    std::shared_ptr<SelectedNodeAccess> selectedNodeAccess;
    std::weak_ptr<HierarchyNode> selectedNode;
    std::shared_ptr<AddCommandService> commandService;
};

#endif //PRESENTER_PROPERTIESEXPLORERPRESENTER_H