#ifndef PRESENTER_EVALUATEMENUPRESENTER_H
#define PRESENTER_EVALUATEMENUPRESENTER_H

#include <utilities/Observer/Observer.h>
#include <presenter/presenter_Export.h>
#include <memory>
#include <string>

class EvaluateMenu;
class ViewFactory;
class SelectedNodeAccess;
class Shell;

class EvaluateMenuPresenter;
typedef std::shared_ptr<EvaluateMenuPresenter> EvaluateMenuPresenterPtr;

class presenter_EXPORT EvaluateMenuPresenter : public Observer {
public:
    static EvaluateMenuPresenterPtr getNewInstance(EvaluateMenu *evaluateMenu, Shell* shell, std::shared_ptr<SelectedNodeAccess> selectedNodeAccess, std::shared_ptr<ViewFactory> viewFactory);
    virtual ~EvaluateMenuPresenter();

    virtual void onEntryClicked(std::string entry);
protected:
    EvaluateMenuPresenter(EvaluateMenu *evaluateMenu, Shell* shell, std::shared_ptr<SelectedNodeAccess> selectedNodeAccess, std::shared_ptr<ViewFactory> viewFactory);

    virtual void update();
private:
    EvaluateMenu* evaluateMenu;
    std::shared_ptr<SelectedNodeAccess> selectedNodeAccess;
    std::shared_ptr<ViewFactory> viewFactory;
    Shell* shell;
};

#endif //PRESENTER_EVALUATEMENUPRESENTER_H