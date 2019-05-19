#ifndef UTILITIES_COMPOSITEIMP_H
#define UTILITIES_COMPOSITEIMP_H

#include <utilities/Composite/Composite.h>

class CompositeImp;
typedef std::shared_ptr<CompositeImp> CompositeImpPtr;

class utilities_EXPORT CompositeImp : public Composite {
public:
    static CompositeImpPtr getNewInstance();
    virtual ~CompositeImp();
protected:
    CompositeImp();

public:
    virtual void insertChild(CompositePtr child, int index) override;
    virtual void appendChild(CompositePtr child) override;
    virtual void setChildAt(CompositePtr child, int index) override;
    virtual void removeChild(int index) override;

    virtual CompositePtr getChildAt(int pos) override;
    virtual int getChildCount() override;
    virtual int childPos(CompositePtr child) override;
private:
    CompositeImpPtr sharedFromThis();

protected:
    std::vector<CompositePtr> children;
};


#endif //UTILITIES_COMPOSITEIMP_H