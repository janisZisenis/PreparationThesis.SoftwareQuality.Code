#include "MyQAddNodeMenu.h"
#include "presenter/MenuPresenter/AddNodeMenuPresenter/AddNodeMenuPresenter.h"

MyQAddNodeMenu::MyQAddNodeMenu() : QMenu("Add") {
    initializeComponent();
};
MyQAddNodeMenu::~MyQAddNodeMenu() {};

void MyQAddNodeMenu::addEntry(std::string entry) {
    this->addAction(new QAction(QString::fromStdString(entry), nullptr));
}

void MyQAddNodeMenu::setPresenter(std::shared_ptr<AddNodeMenuPresenter> presenter) {
    this->presenter = presenter;
};

void MyQAddNodeMenu::initializeComponent() {
    connect(this, SIGNAL(triggered(QAction*)), this, SLOT(entryClicked(QAction*)));
}

void MyQAddNodeMenu::entryClicked(QAction* action) {
    presenter->onEntryClicked(action->text().toStdString());
}

