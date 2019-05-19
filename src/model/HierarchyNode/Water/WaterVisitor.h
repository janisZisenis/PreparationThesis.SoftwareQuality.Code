#ifndef MODEL_WATERVISITOR_H
#define MODEL_WATERVISITOR_H

#include <memory>

class Water;

class WaterVisitor;
typedef std::shared_ptr<WaterVisitor> WaterVisitorPtr;

class WaterVisitor {
protected:
	WaterVisitor() {};

public:
	virtual void visit(std::shared_ptr<Water> water) = 0;
};

#endif //MODEL_WATERVISITOR_H