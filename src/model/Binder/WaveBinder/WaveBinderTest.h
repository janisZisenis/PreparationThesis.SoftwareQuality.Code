#ifndef MODEL_WAVEBINDERTEST_H
#define MODEL_WAVEBINDERTEST_H

#include "gmock/gmock.h"
#include "WaveBinder.h"

#include "model/HierarchyNode/BasicElements/Wave/WaveMocks.h"

#include "model/HierarchyNode/Projects/WaveDynamic/WaveDynamicMocks.h"
#include "model/HierarchyNode/Workbook/WorkbookMocks.h"

class WaveBinderTest : public testing::Test
{
protected:
	virtual void SetUp() override
	{
		wave = WaveSubClass::getNewInstance();
		sut = WaveBinder::getNewInstance(wave);
	}
	WaveSubClassPtr wave;
	WaveBinderPtr sut;
};

#endif //MODEL_WAVEBINDERTEST_H