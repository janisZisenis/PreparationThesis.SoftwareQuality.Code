#include "MyQViewFactoryImp.h"

#include <model/HierarchyNode/AllNodeTypeIncludes.h>
#include <presenter/MenuPresenter/ViewMenuPresenter/View.h>
#include <model/HierarchyNode/AllNodeIncludes.h>
#include <sstream>
#include <presenter/EvaluationViewPresenter/WaveDynamic/WaveProfilePresenter/WaveProfilePresenter.h>
#include <qtView/MyQEvaluationView/WaveDynamic/MyQWaveProfileView/MyQWaveProfileView.h>
#include <presenter/EvaluationViewPresenter/WaveDynamic/WaveKinematicPresenter/WaveKinematicPresenter.h>
#include <qtView/MyQEvaluationView/WaveDynamic/MyQWaveKinematicView/MyQWaveKinematicView.h>

MyQViewFactoryImpPtr MyQViewFactoryImp::getNewInstance() {
    return MyQViewFactoryImpPtr(new MyQViewFactoryImp());
}

MyQViewFactoryImp::~MyQViewFactoryImp() {}

MyQViewFactoryImp::MyQViewFactoryImp() {}

std::vector<std::string> MyQViewFactoryImp::getListOfVisualizationsFor(std::string type) {
    if (type == NodeTypes::waveDynamic()) return getWaveDynamicList();

    return getEmptyList();
}

std::vector<std::string> MyQViewFactoryImp::getWaveDynamicList() {
    std::vector<std::string> list;
    list.push_back("Wave Kinematic");
    list.push_back("Wave Profile");

    return list;
}

std::vector<std::string> MyQViewFactoryImp::getEmptyList() {
    return std::vector<std::string>();
}

View *MyQViewFactoryImp::makeView(std::string type, HierarchyNodePtr node) {

    if (type == "Wave Profile") return makeWaveProfileView(node);
    if (type == "Wave Kinematic") return makeWaveKinematicView(node);

    throw new InvalidViewTypeException();
}

const char *InvalidViewTypeException::what() const throw() {
    std::ostringstream getNr;
    getNr << "Invalid view type!";
    return getNr.str().c_str();
}

View* MyQViewFactoryImp::makeWaveKinematicView(HierarchyNodePtr node) {
    WaveDynamicPtr waveDynamic = std::dynamic_pointer_cast<WaveDynamic>(node);

    MyQWaveKinematicView* view = new MyQWaveKinematicView();
    WaveKinematicPresenterPtr presenter = WaveKinematicPresenter::getNewInstance(view, waveDynamic);
    view->setPresenter(presenter);

    return view;
}

View *MyQViewFactoryImp::makeWaveProfileView(HierarchyNodePtr node) {
    WaveDynamicPtr waveDynamic = std::dynamic_pointer_cast<WaveDynamic>(node);

    MyQWaveProfileView* view = new MyQWaveProfileView();
    WaveProfilePresenterPtr presenter = WaveProfilePresenter::getNewInstance(view, waveDynamic);
    view->setPresenter(presenter);

    return view;
}