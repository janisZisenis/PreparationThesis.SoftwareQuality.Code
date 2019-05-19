#ifndef QTVIEW_MYQSHELL_H
#define QTVIEW_MYQSHELL_H

#include <qtView/qtView_Export.h>
#include <QMainWindow>
#include <vector>
#include <presenter/Shell/Shell.h>

class qtView_EXPORT MyQShell : public QMainWindow, public Shell {
public:
	MyQShell();
	virtual ~MyQShell();

	virtual void addMenu(QMenu* menu);
	virtual void addEvalutationView(View *view) override;
	virtual void addInspectorView(View *view) override;

	virtual void initializeComponent();

private:
	QMainWindow *central;
	QMenuBar* menuBar;
	std::vector<QDockWidget*> docks;
};


#endif //QTVIEW_MYQSHELL_H