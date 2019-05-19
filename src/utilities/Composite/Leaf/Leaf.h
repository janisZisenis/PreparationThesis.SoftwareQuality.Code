#ifndef UTILITIES_LEAF_H
#define UTILITIES_LEAF_H

#include <utilities/Composite/Composite.h>

class Composite;

class Leaf;
typedef std::shared_ptr<Leaf> LeafPtr;
class utilities_EXPORT Leaf : public Composite {
public:
    static LeafPtr getNewInstance();
    virtual ~Leaf();
protected:
    Leaf();

public:
    virtual void insertChild(CompositePtr child, int index) override;
    virtual void appendChild(CompositePtr child) override;
    virtual void setChildAt(CompositePtr child, int index) override;
    virtual void removeChild(int index) override;

    virtual CompositePtr getChildAt(int pos) override;
    virtual int getChildCount() override;
    virtual int childPos(CompositePtr child) override;
private:
    LeafPtr sharedFromThis();
};


#endif //UTILITIES_LEAF_H