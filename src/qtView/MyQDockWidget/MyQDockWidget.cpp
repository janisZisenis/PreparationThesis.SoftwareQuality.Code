#include "MyQDockWidget.h"

MyQDockWidget::MyQDockWidget(std::string title) : QDockWidget(QString::fromStdString(title)) {
    this->setVisible(true);
}

MyQDockWidget::~MyQDockWidget() {}

void MyQDockWidget::changeVisibility() {
    if (QDockWidget::isVisible())
        this->setVisible(false);
    else
        this->setVisible(true);
}

bool MyQDockWidget::isVisible() {
    return QDockWidget::isVisible();
}

std::string MyQDockWidget::getTitle() {
    return windowTitle().toStdString();
}

