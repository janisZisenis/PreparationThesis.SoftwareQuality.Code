#ifndef ITEM_HIERARCHICITEM_H
#define ITEM_HIERARCHICITEM_H

#include <memory>
#include <item/item_Export.h>
#include <utilities/Object/Object.h>
#include <boost/signals2/signal.hpp>


class HierarchicItem;
typedef std::shared_ptr<HierarchicItem> HierarchicItemPtr;

class item_EXPORT HierarchicItem : public Object {
public:
public:
	virtual ~HierarchicItem();
protected:
	HierarchicItem();
public:
	boost::signals2::signal<void (const HierarchicItemPtr emiting, const int index)> beginInsertChild;
	boost::signals2::signal<void ()> endInsertChild;
	boost::signals2::signal<void (const HierarchicItemPtr emiting, const int index)> beginRemoveChild;
	boost::signals2::signal<void ()> endRemoveChild;
	boost::signals2::signal<void (const HierarchicItemPtr emiting, const int index)> beginReplaceChild;
	boost::signals2::signal<void ()> endReplaceChild;
	boost::signals2::signal<void (const HierarchicItemPtr emiting)> itemDataChanged;
protected: //slots
	virtual void onBeginInsertChild(const HierarchicItemPtr emiting, const int index);
	virtual void onEndInsertChild();
	virtual void onBeginRemoveChild(const HierarchicItemPtr emiting, const int index);
	virtual void onEndRemoveChild();
	virtual void onBeginReplaceChild(const HierarchicItemPtr emiting, const int index);
	virtual void onEndReplaceChild();
	virtual void onItemDataChanged(const HierarchicItemPtr item);

public:
	virtual bool isEditable();
	virtual void enableEditing();
	virtual void disableEditing();

	virtual HierarchicItemPtr getParent();
	virtual void setParent(HierarchicItemPtr parent);
	virtual int getRow();

	virtual HierarchicItemPtr getChildAt(int pos) = 0;
	virtual int getChildCount() = 0;
	virtual int childPos(HierarchicItemPtr child) = 0;

protected:
	void connectToChild(HierarchicItemPtr child);
	void disconnectFromChild(HierarchicItemPtr child);

private:
	HierarchicItemPtr sharedFromThis();

protected:
	std::weak_ptr<HierarchicItem> parent;
	bool allowEditing = true;
};



#endif //ITEM_HIERARCHICITEM_H