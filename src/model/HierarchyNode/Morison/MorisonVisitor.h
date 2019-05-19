#ifndef MODEL_MORISONVISITOR_H
#define MODEL_MORISONVISITOR_H

#include <memory>

class Morison;

class MorisonVisitor;
typedef std::shared_ptr<MorisonVisitor> MorisonVisitorPtr;

class MorisonVisitor {
protected:
	MorisonVisitor() {};

public:
	virtual void visit(std::shared_ptr<Morison> morison) = 0;
};

#endif //MODEL_MORISONVISITOR_H