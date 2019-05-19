#ifndef QTVIEW_WAVEKINEMATICPRESENTER_H
#define QTVIEW_WAVEKINEMATICPRESENTER_H

#include <memory>
#include <presenter/presenter_Export.h>

class HierarchyNode;
class WaveDynamic;
class WaveKinematicView;

class WaveKinematicPresenter;
typedef std::shared_ptr<WaveKinematicPresenter> WaveKinematicPresenterPtr;

class presenter_EXPORT WaveKinematicPresenter {
public:
	static WaveKinematicPresenterPtr getNewInstance(WaveKinematicView *view, std::shared_ptr<WaveDynamic> waveDynamic);
	virtual ~WaveKinematicPresenter();
protected:
	WaveKinematicPresenter(WaveKinematicView *view, std::shared_ptr<WaveDynamic> waveDynamic);
protected: //slots
	virtual void onNodeChanged(const std::shared_ptr<HierarchyNode> changed);
public:
	virtual void updateView();
	virtual void setTitleToView();

private:
	std::shared_ptr<WaveDynamic> waveDynamic;
	WaveKinematicView* view;
};


#endif //QTVIEW_WAVEKINEMATICPRESENTER_H