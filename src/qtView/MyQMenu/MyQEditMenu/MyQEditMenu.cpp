#include "MyQEditMenu.h"
#include <presenter/MenuPresenter/EditMenuPresenter/EditMenuPresenter.h>

MyQEditMenu::MyQEditMenu() : QMenu("Edit"), undoAction(new QAction("Undo", nullptr)), redoAction(new QAction("Redo", nullptr)) {
    initializeComponent();
}
MyQEditMenu::~MyQEditMenu() {}

void MyQEditMenu::setPresenter(EditMenuPresenterPtr presenter) {
    this->presenter = presenter;
}

void MyQEditMenu::disableUndo() {
    undoAction->setDisabled(true);
}

void MyQEditMenu::enableUndo() {
    undoAction->setEnabled(true);
}

void MyQEditMenu::disableRedo() {
    redoAction->setDisabled(true);
}

void MyQEditMenu::enableRedo() {
    redoAction->setEnabled(true);
}

void MyQEditMenu::initializeComponent() {
    this->addAction(undoAction);
    this->addAction(redoAction);

    connect(undoAction, SIGNAL(triggered()), this, SLOT(undoClicked()));
    connect(redoAction, SIGNAL(triggered()), this, SLOT(redoClicked()));
}

void MyQEditMenu::undoClicked() {
    presenter->onUndoClick();
}

void MyQEditMenu::redoClicked() {
    presenter->onRedoClick();
}
