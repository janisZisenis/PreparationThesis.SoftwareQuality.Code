#pragma once
#include <memory>
#include "qtView/MyQDockWidget/MyQDockWidget.h"
#include "presenter/EvaluationViewPresenter/WaveDynamic/WaveKinematicPresenter/WaveKinematicView.h"

class WaveKinematicPresenter;


class MyQWaveKinematicView: public MyQDockWidget, public WaveKinematicView {
public:
	Q_OBJECT
public:
	MyQWaveKinematicView();
	virtual ~MyQWaveKinematicView();
	
	virtual void setTitle(std::string title) override;
	std::string getTitle() override;
	virtual void changeVisibility() override;
	virtual bool isVisible() override;

	virtual void setPresenter(std::shared_ptr<WaveKinematicPresenter> presenter);

private:
	void initializeComponent();

private:
	std::shared_ptr<WaveKinematicPresenter> presenter;
};
