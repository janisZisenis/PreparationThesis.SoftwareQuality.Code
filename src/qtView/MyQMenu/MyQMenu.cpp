#include "MyQMenu.h"

MyQMenu::MyQMenu(std::string title) : QMenu(nullptr)
{
	this->setTitle(QString::fromStdString(title));
}
MyQMenu::~MyQMenu() {}

void MyQMenu::addCheckableEntry(std::string entry)
{
	QAction *action = new QAction(QString::fromStdString(entry), this);
	action->setCheckable(true);
	this->addAction(action);
}

void MyQMenu::addUncheckableEntry(std::string entry)
{
	QAction *action = new QAction(QString::fromStdString(entry), this);
	action->setCheckable(false);
	this->addAction(action);
}

void MyQMenu::setEntryChecked(std::string entry)
{
	QAction* action = findQAction(QString::fromStdString(entry));

	if (action) action->setChecked(true);
}

void MyQMenu::setEntryUnchecked(std::string entry)
{
	QAction* action = findQAction(QString::fromStdString(entry));

	if (action) action->setChecked(false);
}

bool MyQMenu::entryExists(std::string entry)
{
	if (findQAction(QString::fromStdString(entry)))
		return true;

	return false;
}

void MyQMenu::enableMenu()
{
	QMenu::setEnabled(true);
}
void MyQMenu::disableMenu()
{
	QMenu::setDisabled(true);
}

QAction* MyQMenu::findQAction(const QString entry)
{
	QAction *action = nullptr;

	QList<QAction*> myActions = this->actions();

	for (QList<QAction*>::iterator it = myActions.begin(); it != myActions.end(); it++)
	{
		QString qstring = (*it)->text();
		if ((*it)->text() == entry)
		{
			(*it)->setChecked(true);
			action = (*it);
			break;
		}
	}

	return action;
}