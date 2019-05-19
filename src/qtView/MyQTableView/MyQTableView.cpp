#include "MyQTableView.h"
#include "MyQItemTableModel.h"
#include <QHeaderView>

MyQTableView::MyQTableView() : QTableView() {
	initializeComponent();
}

MyQTableView::~MyQTableView() {}

void MyQTableView::setMyQItemTableModel(MyQItemTableModel *model) {
	setModel(model);

	if(this->model) delete this->model;
	
	this->model = model;
}

void MyQTableView::initializeComponent() {
    horizontalHeader()->setStretchLastSection(true);
	horizontalHeader()->setDefaultAlignment(Qt::AlignmentFlag::AlignLeft);
    horizontalHeader()->setSectionsClickable(false);
	verticalHeader()->setDefaultSectionSize(20);
    verticalHeader()->hide();
}
