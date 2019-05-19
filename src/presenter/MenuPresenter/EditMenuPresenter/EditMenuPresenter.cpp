#include "EditMenuPresenter.h"
#include <utilities/CommandQueue/CommandQueue.h>
#include "EditMenu.h"

EditMenuPresenterPtr EditMenuPresenter::getNewInstance(EditMenu *editMenu, CommandQueuePtr commandQueue) {
    return EditMenuPresenterPtr(new EditMenuPresenter(editMenu, commandQueue));
}
EditMenuPresenter::~EditMenuPresenter() {}
EditMenuPresenter::EditMenuPresenter(EditMenu *editMenu, CommandQueuePtr commandQueue)
        : editMenu(editMenu), commandQueue(commandQueue) {
    update();
}

void EditMenuPresenter::update() {
    if(commandQueue->undoIsPossible()) editMenu->enableUndo();
    else editMenu->disableUndo();

    if(commandQueue->redoIsPossible()) editMenu->enableRedo();
    else editMenu->disableRedo();
}

void EditMenuPresenter::onUndoClick() {
    commandQueue->undo();
}

void EditMenuPresenter::onRedoClick() {
    commandQueue->redo();
}

