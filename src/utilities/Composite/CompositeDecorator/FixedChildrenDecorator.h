//#ifndef UTILITIES_FIXEDCHILDRENDECORATOR_H
//#define UTILITIES_FIXEDCHILDRENDECORATOR_H
//
//#include <utilities/Composite/CompositeDecorator/CompositeDecorator.h>
//
//class FixedChildrenDecorator;
//typedef std::shared_ptr<FixedChildrenDecorator> FixedChildrenDecoratorPtr;
//class utilities_EXPORT FixedChildrenDecorator : public CompositeDecorator {
//public:
//    static FixedChildrenDecoratorPtr getNewInstance(int numOfChildren, CompositePtr composite);
//    virtual ~FixedChildrenDecorator();
//protected:
//    FixedChildrenDecorator(int numOfChildren, CompositePtr composite);
//public:
//    virtual void insertChild(CompositePtr child, int index) override;
//    virtual void appendChild(CompositePtr child) override;
//    virtual void setChildAt(CompositePtr child, int index) override;
//    virtual void removeChild(int index) override;
//
//private:
//    FixedChildrenDecoratorPtr sharedFromThis();
//protected:
//    int numOfChildren;
//};
//
//#endif //UTILITIES_FIXEDCHILDRENDECORATOR_H