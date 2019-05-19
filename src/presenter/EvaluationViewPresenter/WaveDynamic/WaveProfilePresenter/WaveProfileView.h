#ifndef PRESENTER_WAVEPROFILEVIEW_H
#define PRESENTER_WAVEPROFILEVIEW_H

#include <presenter/MenuPresenter/ViewMenuPresenter/View.h>
#include <vector>

class WaveProfileView : public View {
public:
	virtual void setTitle(std::string title) = 0;
	virtual void setAngularWaveNumber(double waveNumber) = 0;
	virtual void setAngularWaveFrequency(double frequency) = 0;
	virtual void setWaterDisplacement(double displacement) = 0;
	virtual void setSpatialViewingData(std::vector<double> x, std::vector<double> y) = 0;
	virtual void setTimeViewingData(std::vector<double> x, std::vector<double> y) = 0;

	virtual void repaint() = 0;
};

#endif //PRESENTER_WAVEPROFILEVIEW_H