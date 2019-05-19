#pragma once

#include "presenter/MenuPresenter/ViewMenuPresenter/View.h"

class WaveKinematicView : public View {
public:
    virtual void setTitle(std::string title) = 0;
};