#include "MyQViewMenu.h"
#include <presenter/MenuPresenter/ViewMenuPresenter/ViewMenuPresenter.h>

MyQViewMenu::MyQViewMenu() : QMenu("View") {
    this->initializeComponent();
}

MyQViewMenu::~MyQViewMenu() {}

void MyQViewMenu::clearEntries(){
    QMenu::clear();
}

void MyQViewMenu::addCheckedEntry(std::string entry) {
    QAction* action = createCheckableAction(entry);
    action->setChecked(true);
    this->addAction(action);
}

void MyQViewMenu::addUncheckedEntry(std::string entry) {
    QAction* action = createCheckableAction(entry);
    action->setChecked(false);
    this->addAction(action);
}

void MyQViewMenu::setPresenter(ViewMenuPresenterPtr presenter) {
    this->presenter = presenter;
}

QAction* MyQViewMenu::createCheckableAction(std::string entry) {
    QAction* action = new QAction(QString::fromStdString(entry), nullptr);
    action->setCheckable(true);

    return action;
}

void MyQViewMenu::initializeComponent() {
    connect(this, SIGNAL(triggered(QAction*)), this, SLOT(entryClicked(QAction*)));
}

void MyQViewMenu::entryClicked(QAction* action) {
    this->presenter->onEntryClicked(action->text().toStdString());
}