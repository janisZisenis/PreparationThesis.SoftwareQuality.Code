#include "ViewMenuPresenter.h"
#include "ViewMenu.h"
#include "View.h"
#include <presenter/Shell/Shell.h>

ViewMenuPresenterPtr ViewMenuPresenter::getNewInstance(ViewMenu *viewMenu, Shell* shell) {
    return ViewMenuPresenterPtr(new ViewMenuPresenter(viewMenu, shell));
}

ViewMenuPresenter::~ViewMenuPresenter() {}

ViewMenuPresenter::ViewMenuPresenter(ViewMenu *viewMenu, Shell* shell) : viewMenu(viewMenu), shell(shell) {}

void ViewMenuPresenter::addView(View *view) {
    views.push_back(view);
    shell->addInspectorView(view);

    update();
}

void ViewMenuPresenter::onEntryClicked(std::string name) {
    for(View* view : views)
        if(view->getTitle() == name) view->changeVisibility();
}

void ViewMenuPresenter::update() {
    viewMenu->clearEntries();

    for(View* view : views)
        if(view->isVisible()) viewMenu->addCheckedEntry(view->getTitle());
        else viewMenu->addUncheckedEntry(view->getTitle());
}
