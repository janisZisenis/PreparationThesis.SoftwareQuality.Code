#ifndef QTVIEW_MYQMENU_H
#define QTVIEW_MYQMENU_H

#include <qtView/qtView_Export.h>
#include <QMenu>
#include <memory>
#include <string>

class qtView_EXPORT MyQMenu : public QMenu
{
public:
	MyQMenu(std::string title);
	virtual ~MyQMenu();

	virtual void addCheckableEntry(std::string entry);
	virtual void addUncheckableEntry(std::string entry);
	virtual void setEntryChecked(std::string entry);
	virtual void setEntryUnchecked(std::string entry);
	virtual bool entryExists(std::string entry);
	virtual void enableMenu();
	virtual void disableMenu();

private:
	virtual QAction* findQAction(const QString entry);
};


#endif //QTVIEW_MYQMENU_H