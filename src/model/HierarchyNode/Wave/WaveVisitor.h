#ifndef MODEL_WAVEVISITOR_H
#define MODEL_WAVEVISITOR_H

#include <memory>

class Wave;

class WaveVisitor;
typedef std::shared_ptr<WaveVisitor> WaveVisitorPtr;

class WaveVisitor {
protected:
	WaveVisitor() {};

public:
	virtual void visit(std::shared_ptr<Wave> wave) = 0;
};

#endif //MODEL_WAVEVISITOR_H