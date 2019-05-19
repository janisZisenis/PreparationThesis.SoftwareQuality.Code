#ifndef MODEL_WAVEMOCKS_H
#define MODEL_WAVEMOCKS_H

#include "Wave.h"

class WaveSubClass;
typedef shared_ptr<WaveSubClass> WaveSubClassPtr;
class WaveSubClass : public Wave
{
public:
	static WaveSubClassPtr getNewInstance()
	{
		return WaveSubClassPtr(new WaveSubClass());
	}
	virtual ~WaveSubClass() {}
protected:
	WaveSubClass() : Wave() {}
public:

};

class WaveSubClassPropertiesStub;
typedef shared_ptr<WaveSubClassPropertiesStub> WaveSubClassPropertiesStubPtr;
class WaveSubClassPropertiesStub : public WaveSubClass
{
public:
	static WaveSubClassPropertiesStubPtr getNewInstance()
	{
		return WaveSubClassPropertiesStubPtr(new WaveSubClassPropertiesStub());
	};
	virtual ~WaveSubClassPropertiesStub() {};
protected:
	WaveSubClassPropertiesStub() : WaveSubClass() {};

public:
	virtual void setProperties(string name, double waveLength, double wavePeriod, double waveHeight, double waterDepth, double angularNumber, double angularFrequency)
	{
		stubName = name;
		stubWaveLength = waveLength;
		stubWavePeriod = wavePeriod;
		stubWaveHeight = waveHeight;
		stubWaterDepth = waterDepth;
		stubAngularNumber = angularNumber;
		stubAngularFrequency = angularFrequency;
	}

	virtual string getName() override
	{
		return stubName;
	}
	virtual double getLength() override
	{
		return stubWaveLength;
	}
	virtual double getPeriod() override
	{
		return stubWavePeriod;
	}
	virtual double getHeight() override
	{
		return stubWaveHeight;
	}
	virtual double getWaterDepth() override
	{
		return stubWaterDepth;
	}
	virtual double getAngularNumber() override
	{
		return stubAngularNumber;
	}
	virtual double getAngularFrequency() override
	{
		return stubAngularFrequency;
	}

private:
	string stubName;
	double stubWaveLength;
	double stubWavePeriod;
	double stubWaveHeight;
	double stubWaterDepth;
	double stubAngularNumber;
	double stubAngularFrequency;
};

#endif //MODEL_WAVEMOCKS_H