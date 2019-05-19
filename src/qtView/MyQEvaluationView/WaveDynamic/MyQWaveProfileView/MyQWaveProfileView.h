#ifndef QTVIEW_MYQWAVEPROFILEVIEW_H
#define QTVIEW_MYQWAVEPROFILEVIEW_H

#include <memory>
#include "presenter/EvaluationViewPresenter/WaveDynamic/WaveProfilePresenter/WaveProfileView.h"
#include <qtView/MyQDockWidget/MyQDockWidget.h>

class WaveProfilePresenter;

class MyQCustomTable;
class QLabel;
class QCustomPlot;
class QHBoxLayout;
class QVBoxLayout;
class QCPGraph;
class QCPAxis;

class MyQWaveProfileView : public MyQDockWidget, public WaveProfileView {
public:
	Q_OBJECT
public:
	MyQWaveProfileView();
	virtual ~MyQWaveProfileView();

	std::string getTitle() override;
	bool isVisible() override;
	void changeVisibility() override;
	virtual void setTitle(std::string title) override;
	virtual void setAngularWaveNumber(double waveNumber) override;
	virtual void setAngularWaveFrequency(double frequency) override;
	virtual void setWaterDisplacement(double displacement) override;
	virtual void setSpatialViewingData(std::vector<double> x, std::vector<double> y) override;
	virtual void setTimeViewingData(std::vector<double> x, std::vector<double> y) override;

	virtual void setPresenter(std::shared_ptr<WaveProfilePresenter> presenter);

	virtual void repaint() override;
private:
	void initializeComponent();

	void initializeCentral();

	void initializeResultBlock();
	void initializeBlockTitle();
	void initializeAngularWaveNumber();
	void initializeAngularWaveFrequency();
	void initializeWaterDisplacement();
	void initializeRowsColumns();

	void initializeSpatialViewing();
	void initializeSpatialGraph();
	void initializeTimeViewing();
	void initializeTimeGraph();

	QCustomPlot* createPlotAndAddToCentral();
	void formatCustomPlot(QCustomPlot * plot);
	void initializePlotTitle(QString string, QCustomPlot *plot);
	QCPGraph* createGraphAndAddTo(QCustomPlot* plot);
	void formatGraph(QCPGraph *graph, QPen pen, QColor color);
	void initializeAxisTitles(QCPGraph *graph, QString keyTitle, QString valueTitle);

	void setAxisRanges(QCPGraph *graph, QVector<double> qX, QVector<double> qY);
	void setAxisRange(QCPAxis *axis, double beginning, double end);
	void setKeyAxisRange(QCPAxis *axis, QVector<double> qX);
	void setValueAxisRange(QCPAxis *axis, QVector<double> qY);

	void repaintComponents();

private:
	std::shared_ptr<WaveProfilePresenter> presenter;
	QWidget *central;
	QVBoxLayout *centralLayout;

	QHBoxLayout *resultBlockLayout;
	MyQCustomTable *resultBlock;

	QCustomPlot* spatialViewing;
	QCustomPlot* timeViewing;

	QCPGraph *spatialGraph;
	QCPGraph *timeGraph;
};

#endif //QTVIEW_MYQWAVEPROFILEVIEW_H