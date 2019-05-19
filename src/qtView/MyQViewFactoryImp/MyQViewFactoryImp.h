#ifndef QTVIEW_MYQVIEWFACTORYIMP_H
#define QTVIEW_MYQVIEWFACTORYIMP_H

#include <qtView/qtView_Export.h>
#include <memory>
#include <presenter/MenuPresenter/EvaluateMenuPresenter/ViewFactory.h>

class MyQViewFactoryImp;
typedef std::shared_ptr<MyQViewFactoryImp> MyQViewFactoryImpPtr;

class qtView_EXPORT MyQViewFactoryImp : public ViewFactory
{
public:
	static MyQViewFactoryImpPtr getNewInstance();
	virtual ~MyQViewFactoryImp();
private:
	MyQViewFactoryImp();
public:
	std::vector<std::string> getListOfVisualizationsFor(std::string type) override;
	View* makeView(std::string type, std::shared_ptr<HierarchyNode> node) override;

private:
	View* makeWaveProfileView(std::shared_ptr<HierarchyNode> node);
	View* makeWaveKinematicView(std::shared_ptr<HierarchyNode> node);

	std::vector<std::string> getWaveDynamicList();
    std::vector<std::string> getEmptyList();
};

class InvalidViewTypeException : public std::exception {
public:
	virtual const char *what() const throw();
};

#endif //QTVIEW_MYQVIEWFACTORYIMP_H