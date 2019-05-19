#include "MyQWaveProfileView.h"
#include "model/HierarchyNode/WaveDynamic/WaveDynamic.h"
#include <QLabel>
#include <QGridLayout>
#include "qcustomplot.h"
#include <QSpacerItem>
#include <qtView/MyQCustomTable/MyQCustomTable.h>
#include <presenter/EvaluationViewPresenter/WaveDynamic/WaveProfilePresenter/WaveProfilePresenter.h>
#include "utilities/Math/Math.h"
#include "qtView/MyQUtilities/MyQUtilities.h"

MyQWaveProfileView::MyQWaveProfileView() : MyQDockWidget("") {
    this->initializeComponent();
}

MyQWaveProfileView::~MyQWaveProfileView() {}

std::string MyQWaveProfileView::getTitle() {
    return MyQDockWidget::getTitle();
}

bool MyQWaveProfileView::isVisible() {
    return MyQDockWidget::isVisible();
}

void MyQWaveProfileView::changeVisibility() {
    MyQDockWidget::changeVisibility();
}

void MyQWaveProfileView::setTitle(std::string title) {
    setWindowTitle(QString::fromStdString(title));
}

void MyQWaveProfileView::setAngularWaveNumber(double waveNumber) {
    resultBlock->setText(1, 2, std::to_string(waveNumber));
}

void MyQWaveProfileView::setAngularWaveFrequency(double frequency) {
    resultBlock->setText(2, 2, std::to_string(frequency));
}

void MyQWaveProfileView::setWaterDisplacement(double displacement) {
    resultBlock->setText(3, 2, std::to_string(displacement));
}

void MyQWaveProfileView::setSpatialViewingData(std::vector<double> x, std::vector<double> y) {
    QVector<double> qX = MyQUtilities::transformToQVector(x);
    QVector<double> qY = MyQUtilities::transformToQVector(y);

    spatialGraph->setData(qX, qY);
    setAxisRanges(spatialGraph, qX, qY);
}

void MyQWaveProfileView::setTimeViewingData(std::vector<double> x, std::vector<double> y) {
    QVector<double> qX = MyQUtilities::transformToQVector(x);
    QVector<double> qY = MyQUtilities::transformToQVector(y);

    timeGraph->setData(qX, qY);
    setAxisRanges(timeGraph, qX, qY);
}

void MyQWaveProfileView::setPresenter(WaveProfilePresenterPtr presenter) {
    this->presenter = presenter;
}

void MyQWaveProfileView::repaint() {
    QDockWidget::repaint();

    repaintComponents();
}

void MyQWaveProfileView::initializeComponent() {
    initializeCentral();
    initializeResultBlock();
    initializeSpatialViewing();
    initializeTimeViewing();
}

void MyQWaveProfileView::initializeCentral() {
    this->central = new QWidget(this);
    this->setWidget(central);
    this->centralLayout = new QVBoxLayout();
    central->setLayout(centralLayout);
}

void MyQWaveProfileView::initializeResultBlock() {
    resultBlockLayout = new QHBoxLayout();
    centralLayout->addLayout(resultBlockLayout);

    resultBlock = new MyQCustomTable(4, 3);

    QSpacerItem *spacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Fixed);

    resultBlockLayout->addWidget(resultBlock);
    resultBlockLayout->addItem(spacer);

    initializeBlockTitle();
    initializeAngularWaveNumber();
    initializeAngularWaveFrequency();
    initializeWaterDisplacement();

    initializeRowsColumns();
}

void MyQWaveProfileView::initializeBlockTitle() {
    resultBlock->bindCells(0, 0, 0, 1);
    resultBlock->bindCells(0, 1, 0, 2);
    resultBlock->setCellAlignment(0, 0, Qt::AlignCenter);
    resultBlock->setCellColor(0, 0, QColor(155, 194, 230));
    resultBlock->setText(0, 0, "Wave Profile");
    resultBlock->setBottomBorderWidth(0, 0, 2);
}

void MyQWaveProfileView::initializeAngularWaveNumber() {
    resultBlock->setText(1, 0, "Angular Wave Number");
    resultBlock->setText(1, 1, "k [rad/m] =");
    resultBlock->setRightBorderWidth(1, 1, 0);
    resultBlock->setLeftBorderWidth(1, 2, 0);
}

void MyQWaveProfileView::initializeAngularWaveFrequency() {
    resultBlock->setText(2, 0, "Angular Wave Frequency");
    resultBlock->setText(2, 1, "w [rad/s] =");

    resultBlock->setRightBorderWidth(2, 1, 0);
    resultBlock->setLeftBorderWidth(2, 2, 0);
}

void MyQWaveProfileView::initializeWaterDisplacement() {
    resultBlock->setTopBorderWidth(3, 0, 2);
    resultBlock->setCellColor(3, 0, QColor(155, 194, 230));
    resultBlock->setTopBorderWidth(3, 1, 2);
    resultBlock->setRightBorderWidth(3, 1, 0);
    resultBlock->setTopBorderWidth(3, 2, 2);
    resultBlock->setLeftBorderWidth(3, 2, 0);

    resultBlock->setText(3, 0, "Water Surface Displacement");
    resultBlock->setText(3, 1, "n(x,t) [m] =");
}

void MyQWaveProfileView::initializeRowsColumns() {
    resultBlock->setColumnWidth(0, 200);
}

void MyQWaveProfileView::initializeSpatialViewing() {
    spatialViewing = createPlotAndAddToCentral();

    initializePlotTitle("Spatial Viewing", spatialViewing);
    initializeSpatialGraph();
    formatCustomPlot(spatialViewing);
}

void MyQWaveProfileView::initializeSpatialGraph() {
    spatialGraph = createGraphAndAddTo(spatialViewing);
    formatGraph(spatialGraph, QPen(Qt::blue), QColor(0, 0, 255, 20));  //???
    initializeAxisTitles(spatialGraph, "Distance [m]", "Water Profile [m]");
}

void MyQWaveProfileView::initializeTimeViewing() {
    timeViewing = createPlotAndAddToCentral();

    initializePlotTitle("Time Viewing", timeViewing);
    initializeTimeGraph();
    formatCustomPlot(timeViewing);
}

void MyQWaveProfileView::initializeTimeGraph() {
    timeGraph = createGraphAndAddTo(timeViewing);
    formatGraph(timeGraph, QPen(Qt::blue), QColor(0, 0, 255, 20)); //???
    initializeAxisTitles(timeGraph, "Time [s]", "Water Profile [m]");
}

QCustomPlot *MyQWaveProfileView::createPlotAndAddToCentral() {
    QCustomPlot *plot = new QCustomPlot();
    plot->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    centralLayout->addWidget(plot);

    return plot;
}

void MyQWaveProfileView::formatCustomPlot(QCustomPlot *plot) {
    connect(plot->xAxis, SIGNAL(rangeChanged(QCPRange)), plot->xAxis2, SLOT(setRange(QCPRange)));
    connect(plot->yAxis, SIGNAL(rangeChanged(QCPRange)), plot->yAxis2, SLOT(setRange(QCPRange)));

    plot->xAxis2->setVisible(true);
    plot->xAxis2->setTickLabels(false);
    plot->yAxis2->setVisible(true);
    plot->yAxis2->setTickLabels(false);

    plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
}

void MyQWaveProfileView::initializePlotTitle(QString string, QCustomPlot *plot) {
    QCPPlotTitle *title = new QCPPlotTitle(plot, string);
    title->font().setFamily("arial");

    plot->plotLayout()->insertRow(0);
    plot->plotLayout()->addElement(0, 0, title);
}

QCPGraph *MyQWaveProfileView::createGraphAndAddTo(QCustomPlot *plot) {
    QCPGraph *graph = new QCPGraph(plot->xAxis, plot->yAxis);
    plot->addPlottable(graph);
    return graph;
}

void MyQWaveProfileView::formatGraph(QCPGraph *graph, QPen pen, QColor color) {
    graph->setPen(pen); // line color blue for first graph
    graph->setBrush(color); // first graph will be filled with translucent blue
}

void MyQWaveProfileView::initializeAxisTitles(QCPGraph *graph, QString keyTitle, QString valueTitle) {
    graph->keyAxis()->setLabel(keyTitle);
    graph->valueAxis()->setLabel(valueTitle);
}

void MyQWaveProfileView::setAxisRanges(QCPGraph *graph, QVector<double> qX, QVector<double> qY) {
    setKeyAxisRange(graph->keyAxis(), qX);
    setValueAxisRange(graph->valueAxis(), qY);
}

void MyQWaveProfileView::setKeyAxisRange(QCPAxis *axis, QVector<double> qX) {
    setAxisRange(axis, qX[0], qX.last());
}

void MyQWaveProfileView::setValueAxisRange(QCPAxis *axis, QVector<double> qY) {
    QVector<double>::iterator min = std::min_element(qY.begin(), qY.end());
    QVector<double>::iterator max = std::max_element(qY.begin(), qY.end());

    double axisOffset = 0.1 * ((*max) - (*min));

    setAxisRange(axis, (*min) - axisOffset, (*max) + axisOffset);
}

void MyQWaveProfileView::setAxisRange(QCPAxis *axis, double beginning, double end) {
    axis->setRange(QCPRange(beginning, end));
}

void MyQWaveProfileView::repaintComponents() {
    resultBlock->repaint();
    spatialViewing->replot();
    timeViewing->replot();
}

