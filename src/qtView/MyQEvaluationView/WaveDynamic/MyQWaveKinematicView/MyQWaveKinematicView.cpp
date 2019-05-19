#include "MyQWaveKinematicView.h"
#include <QLabel>

MyQWaveKinematicView::MyQWaveKinematicView() : MyQDockWidget("") {
    this->initializeComponent();
}

MyQWaveKinematicView::~MyQWaveKinematicView() {}

std::string MyQWaveKinematicView::getTitle() {
    return MyQDockWidget::getTitle();
}

void MyQWaveKinematicView::changeVisibility() {
    MyQDockWidget::changeVisibility();
}

bool MyQWaveKinematicView::isVisible() {
    return MyQDockWidget::isVisible();
}

void MyQWaveKinematicView::setTitle(std::string title) {
    setWindowTitle(QString::fromStdString(title));
}

void MyQWaveKinematicView::setPresenter(std::shared_ptr<WaveKinematicPresenter> presenter) {
    this->presenter = presenter;
}

void MyQWaveKinematicView::initializeComponent() {
    this->setWidget(new QLabel("Hi, I am a Wave Kinematic View!"));
}
