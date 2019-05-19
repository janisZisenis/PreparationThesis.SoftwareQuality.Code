#ifndef UTILITIES_COMPOSITEDECORATOR_H
#define UTILITIES_COMPOSITEDECORATOR_H

#include <utilities/Composite/Composite.h>

class CompositeDecorator;
typedef std::shared_ptr<CompositeDecorator> CompositeDecoratorPtr;
class utilities_EXPORT CompositeDecorator : public Composite {
public:
    virtual ~CompositeDecorator();
protected:
    CompositeDecorator(CompositePtr composite);

public:
    virtual void insertChild(CompositePtr child, int index) override;
    virtual void appendChild(CompositePtr child) override;
    virtual void setChildAt(CompositePtr child, int index) override;
    virtual void removeChild(int index) override;

    virtual CompositePtr getChildAt(int pos) override;
    virtual int getChildCount() override;
    virtual int childPos(CompositePtr child) override;
private:
    CompositeDecoratorPtr sharedFromThis();
protected:
    CompositePtr composite;
};

#endif //UTILITIES_COMPOSITEDECORATOR_H