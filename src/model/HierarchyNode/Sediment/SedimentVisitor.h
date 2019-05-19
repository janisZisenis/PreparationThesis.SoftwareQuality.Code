#ifndef MODEL_SEDIMENTVISITOR_H
#define MODEL_SEDIMENTVISITOR_H

#include <memory>

class Sediment;

class SedimentVisitor;
typedef std::shared_ptr<SedimentVisitor> SedimentVisitorPtr;

class SedimentVisitor {
protected:
	SedimentVisitor() {};

public:
	virtual void visit(std::shared_ptr<Sediment> sediment) = 0;
};

#endif //MODEL_SEDIMENTVISITOR_H