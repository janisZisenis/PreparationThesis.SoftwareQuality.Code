#include "MyQTreeView.h"
#include "MyQItemTreeModel.h"
#include <QHeaderView>

MyQTreeView::MyQTreeView() : QTreeView() {
    initializeComponent();
}

MyQTreeView::~MyQTreeView() {}

void MyQTreeView::setMyQItemTreeModel(MyQItemTreeModel* model) {
    this->model = model;

	this->setModel(model);
}

const QModelIndex MyQTreeView::getCurrentIndex() {
    if (this->selectedIndexes().size() > 0)
        return this->selectedIndexes()[0];

    return QModelIndex();
}

void MyQTreeView::initializeComponent() {
}

