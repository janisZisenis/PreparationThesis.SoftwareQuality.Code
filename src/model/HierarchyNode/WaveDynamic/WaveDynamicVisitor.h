#ifndef MODEL_WAVEDYNAMICVISITOR_H
#define MODEL_WAVEDYNAMICVISITOR_H

#include <memory>

class WaveDynamic;

class WaveDynamicVisitor;
typedef std::shared_ptr<WaveDynamicVisitor> WaveDynamicVisitorPtr;
class WaveDynamicVisitor {
protected:
    WaveDynamicVisitor() {};

public:
    virtual void visit(std::shared_ptr<WaveDynamic> waveDynamic) = 0;
};

#endif //MODEL_WAVEDYNAMICVISITOR_H