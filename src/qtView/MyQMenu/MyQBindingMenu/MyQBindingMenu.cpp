#include "MyQBindingMenu.h"
#include <presenter/MenuPresenter/BindingMenuPresenter/BindingMenuPresenter.h>

MyQBindingMenu::MyQBindingMenu() : QMenu("Bind") {
    initializeComponent();
}
MyQBindingMenu::~MyQBindingMenu() {}

void MyQBindingMenu::clearEntries() {
    QMenu::clear();
}

void MyQBindingMenu::disableMenu() {
    QMenu::setDisabled(true);
}

void MyQBindingMenu::enableMenu() {
    QMenu::setEnabled(true);
}

bool MyQBindingMenu::containsEntries() {
    return (actions().size() > 0);
}

void MyQBindingMenu::setPresenter(BindingMenuPresenterPtr presenter) {
    this->presenter = presenter;
}

void MyQBindingMenu::initializeComponent() {
    connect(this, SIGNAL(triggered(QAction*)), this, SLOT(entryClicked(QAction * )));
}

void MyQBindingMenu::entryClicked(QAction *action) {
    presenter->onEntryClicked(action->text().toStdString());
}

void MyQBindingMenu::addEntry(std::string entry) {
    this->addAction(new QAction(QString::fromStdString(entry), nullptr));
}
