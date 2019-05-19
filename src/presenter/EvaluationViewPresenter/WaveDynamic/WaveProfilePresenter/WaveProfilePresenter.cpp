#include "WaveProfilePresenter.h"
#include "model/HierarchyNode/WaveDynamic/WaveDynamic.h"
#include "WaveProfileView.h"
#include <vector>

WaveProfilePresenterPtr WaveProfilePresenter::getNewInstance(WaveProfileView *view, WaveDynamicPtr waveDynamic) {
    return WaveProfilePresenterPtr(new WaveProfilePresenter(view, waveDynamic));
}

WaveProfilePresenter::~WaveProfilePresenter() {}

WaveProfilePresenter::WaveProfilePresenter(WaveProfileView *view, WaveDynamicPtr waveDynamic) : view(view), waveDynamic(waveDynamic) {
    waveDynamic->nodeChanged.connect(boost::bind(&WaveProfilePresenter::onNodeChanged, this, _1));
    updateView();
}

void WaveProfilePresenter::onNodeChanged(const std::shared_ptr<HierarchyNode> changed) {
    updateView();
}

void WaveProfilePresenter::updateView() {
    setTitleToView();
    fillAngularWaveNumber();
    fillAngularFrequency();
    fillWaterSurfaceDisplacement();
    calculateSpatialViewingData();
    calculateTimeViewingData();

    view->repaint();
}

void WaveProfilePresenter::setTitleToView() {
    view->setTitle(waveDynamic->getName() + " - Wave Profile");
}

void WaveProfilePresenter::fillAngularWaveNumber() {
    view->setAngularWaveNumber(waveDynamic->getAngularWaveNumber());
}

void WaveProfilePresenter::fillAngularFrequency() {
    view->setAngularWaveFrequency(waveDynamic->getAngularWaveFrequency());
}

void WaveProfilePresenter::fillWaterSurfaceDisplacement() {
    view->setWaterDisplacement(waveDynamic->getWaterSurfaceDisplacement());
}

void WaveProfilePresenter::calculateSpatialViewingData() {
    double waveLength = waveDynamic->getWaveLength();
    std::vector<double> x, y;

    for (double i = 0; i <= waveLength; i = i + waveLength / 100) {
        x.push_back(i);
        y.push_back(waveDynamic->getSpatialWaterProfile(i));
    }

    view->setSpatialViewingData(x, y);
}

void WaveProfilePresenter::calculateTimeViewingData() {
    double wavePeriod = waveDynamic->getWavePeriod();
    std::vector<double> x, y;

    for (double i = 0; i <= wavePeriod; i = i + wavePeriod / 100) {
        x.push_back(i);
        y.push_back(waveDynamic->getTimeWaterProfile(i));
    }

    view->setTimeViewingData(x, y);
}


