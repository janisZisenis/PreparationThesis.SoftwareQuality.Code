#ifndef MODEL_PILEVISITOR_H
#define MODEL_PILEVISITOR_H

#include <memory>

class Pile;

class PileVisitor;
typedef std::shared_ptr<PileVisitor> PileVisitorPtr;

class PileVisitor {
protected:
	PileVisitor() {};

public:
	virtual void visit(std::shared_ptr<Pile> pile) = 0;
};

#endif //MODEL_PILEVISITOR_H