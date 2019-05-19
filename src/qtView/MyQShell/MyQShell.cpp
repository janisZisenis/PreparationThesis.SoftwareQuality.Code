#include "MyQShell.h"
#include <QMenuBar>
#include <QDockWidget>
#include <presenter/MenuPresenter/ViewMenuPresenter/View.h>

MyQShell::MyQShell() : QMainWindow(nullptr, 0) {
    this->central = new QMainWindow(this);
    this->menuBar = new QMenuBar(this);

    initializeComponent();
}

MyQShell::~MyQShell() {}

void MyQShell::initializeComponent() {
    central->setWindowFlags(Qt::Widget);
    this->setCentralWidget(central);

    this->setMenuBar(menuBar);
}

void MyQShell::addMenu(QMenu *menu) {
    menuBar->addMenu(menu);
}

void MyQShell::addEvalutationView(View *view) {
    QDockWidget *qDockWidget = dynamic_cast<QDockWidget *>(view);

    central->addDockWidget(Qt::TopDockWidgetArea, qDockWidget);
}

void MyQShell::addInspectorView(View *view) {
    QDockWidget *qDockWidget = dynamic_cast<QDockWidget *>(view);

    addDockWidget(Qt::RightDockWidgetArea, qDockWidget);
}