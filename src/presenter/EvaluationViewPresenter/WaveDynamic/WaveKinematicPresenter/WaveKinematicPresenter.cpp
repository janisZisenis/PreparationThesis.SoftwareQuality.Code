#include "WaveKinematicPresenter.h"
#include "model/HierarchyNode/WaveDynamic/WaveDynamic.h"
#include "WaveKinematicView.h"

WaveKinematicPresenterPtr WaveKinematicPresenter::getNewInstance(WaveKinematicView *view, WaveDynamicPtr waveDynamic) {
    return WaveKinematicPresenterPtr(new WaveKinematicPresenter(view, waveDynamic));
}

WaveKinematicPresenter::~WaveKinematicPresenter() {}

WaveKinematicPresenter::WaveKinematicPresenter(WaveKinematicView *view, WaveDynamicPtr waveDynamic) : view(view), waveDynamic(waveDynamic) {
    waveDynamic->nodeChanged.connect(boost::bind(&WaveKinematicPresenter::onNodeChanged, this, _1));
    updateView();
}

void WaveKinematicPresenter::onNodeChanged(const std::shared_ptr<HierarchyNode> changed) {
    updateView();
}

void WaveKinematicPresenter::updateView() {
    setTitleToView();
}

void WaveKinematicPresenter::setTitleToView() {
    view->setTitle(waveDynamic->getName() + " - Wave Kinematic");
}


