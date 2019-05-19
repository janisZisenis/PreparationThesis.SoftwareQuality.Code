#ifndef PRESENTER_VIEWMENUPRESENTER_H
#define PRESENTER_VIEWMENUPRESENTER_H

#include <presenter/presenter_Export.h>
#include <memory>
#include <string>
#include <vector>
#include <utilities/Observer/Observer.h>

class ViewMenu;
class View;
class Shell;

class ViewMenuPresenter;
typedef std::shared_ptr<ViewMenuPresenter> ViewMenuPresenterPtr;

class presenter_EXPORT ViewMenuPresenter : public Observer {
public:
	static ViewMenuPresenterPtr getNewInstance(ViewMenu *viewMenu, Shell *shell);
	virtual ~ViewMenuPresenter();
protected:
	ViewMenuPresenter(ViewMenu *viewMenu, Shell* shell);

public:
	virtual void addView(View* view);
	virtual void onEntryClicked(std::string name);

	virtual void update() override;

private:
	ViewMenu * viewMenu;
	Shell* shell;
	std::vector<View*> views;
};

#endif //PRESENTER_VIEWMENUPRESENTER_H