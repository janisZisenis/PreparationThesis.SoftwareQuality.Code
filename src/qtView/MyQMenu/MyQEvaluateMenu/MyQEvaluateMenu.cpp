#include "MyQEvaluateMenu.h"
#include <presenter/MenuPresenter/EvaluateMenuPresenter/EvaluateMenuPresenter.h>

MyQEvaluateMenu::MyQEvaluateMenu() : QMenu("Evaluate") {
    initializeComponent();
}
MyQEvaluateMenu::~MyQEvaluateMenu() {}

void MyQEvaluateMenu::clearEntries() {
    QMenu::clear();
}

void MyQEvaluateMenu::disableMenu() {
    setDisabled(true);
}

void MyQEvaluateMenu::enableMenu() {
    setEnabled(true);
}

bool MyQEvaluateMenu::containsEntries() {
    return (actions().size() > 0);
}

void MyQEvaluateMenu::setPresenter(EvaluateMenuPresenterPtr presenter) {
    this->presenter = presenter;
}

void MyQEvaluateMenu::initializeComponent() {
    connect(this, SIGNAL(triggered(QAction*)), this, SLOT(entryClicked(QAction*)));
}

void MyQEvaluateMenu::entryClicked(QAction *action) {
    presenter->onEntryClicked(action->text().toStdString());
}

void MyQEvaluateMenu::addEntry(std::string entry) {
    this->addAction(new QAction(QString::fromStdString(entry), nullptr));
}