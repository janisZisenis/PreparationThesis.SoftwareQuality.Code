#ifndef PRESENTER_WAVEPROFILEPRESENTER_H
#define PRESENTER_WAVEPROFILEPRESENTER_H

#include <memory>
#include <presenter/presenter_Export.h>

class HierarchyNode;
class WaveDynamic;
class WaveProfileView;

class WaveProfilePresenter;
typedef std::shared_ptr<WaveProfilePresenter> WaveProfilePresenterPtr;

class presenter_EXPORT WaveProfilePresenter {
public:
	static WaveProfilePresenterPtr getNewInstance(WaveProfileView *view, std::shared_ptr<WaveDynamic> waveDynamic);
	virtual ~WaveProfilePresenter();
protected: //slots
	virtual void onNodeChanged(const std::shared_ptr<HierarchyNode> changed);
protected:
	WaveProfilePresenter(WaveProfileView *view, std::shared_ptr<WaveDynamic> waveDynamic);
private:
	virtual void updateView();
	virtual void fillAngularWaveNumber();
	virtual void fillAngularFrequency();
	virtual void fillWaterSurfaceDisplacement();
	virtual void calculateSpatialViewingData();
	virtual void calculateTimeViewingData();
	void setTitleToView();

	std::shared_ptr<WaveDynamic> waveDynamic;
	WaveProfileView* view;
};


#endif //PRESENTER_WAVEPROFILEPRESENTER_H