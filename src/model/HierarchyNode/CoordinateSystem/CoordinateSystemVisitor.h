#ifndef MODEL_COORDINATESYSTEMVISITOR_H
#define MODEL_COORDINATESYSTEMVISITOR_H

#include <memory>

class CoordinateSystem;

class CoordinateSystemVisitor;
typedef std::shared_ptr<CoordinateSystemVisitor> CoordinateSystemVisitorPtr;

class CoordinateSystemVisitor {
protected:
	CoordinateSystemVisitor() {};

public:
	virtual void visit(std::shared_ptr<CoordinateSystem> coordinateSystem) = 0;
};

#endif //MODEL_COORDINATESYSTEMVISITOR_H