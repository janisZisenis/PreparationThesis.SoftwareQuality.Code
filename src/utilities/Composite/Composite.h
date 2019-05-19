#ifndef UTILITIES_COMPOSITE_H
#define UTILITIES_COMPOSITE_H

#include <utilities/Object/Object.h>
#include <utilities/utilities_Export.h>

class Composite;
typedef std::shared_ptr<Composite> CompositePtr;

class utilities_EXPORT Composite : public Object {
public:
    virtual ~Composite();

protected:
    Composite();

public:
    virtual void insertChild(CompositePtr child, int index) = 0;
    virtual void appendChild(CompositePtr child) = 0;
    virtual void setChildAt(CompositePtr child, int index) = 0;
    virtual void removeChild(int index) = 0;

    virtual CompositePtr getChildAt(int pos) = 0;
    virtual int getChildCount() = 0;
    virtual int childPos(CompositePtr child) = 0;

    virtual void setParent(CompositePtr parent);
    virtual CompositePtr getParent();
    virtual int getRow();

protected:
    std::weak_ptr<Composite> parent;

private:
    CompositePtr sharedFromThis();
};


#endif //UTILITIES_COMPOSITE_H