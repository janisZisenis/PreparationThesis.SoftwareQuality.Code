#ifndef MODEL_MORISON_H
#define MODEL_MORISON_H

#include "model/HierarchyNode/HierarchyNode.h"

class Pile;
class Water;
class WaveDynamic;

class Morison;
typedef std::shared_ptr<Morison> MorisonPtr;

class model_EXPORT Morison : public HierarchyNode {
public:
	static MorisonPtr getNewInstance();
	virtual ~Morison();
protected:
	Morison();

public:
	virtual void setPile(std::shared_ptr<Pile> pile);
	virtual std::shared_ptr<Pile> getPile();

	virtual void setWater(std::shared_ptr<Water> water);
	virtual std::shared_ptr<Water> getWater();

	virtual void setWaveDynamic(std::shared_ptr<WaveDynamic> waveDynamic);
	std::shared_ptr<WaveDynamic> getWaveDynamic();

	virtual bool canBind(HierarchyNodePtr node) override;
	virtual std::shared_ptr<Visitor> makeBinder() override;
	virtual std::shared_ptr<Editor> makeEditor() override;
	virtual void accept(std::shared_ptr<Visitor> visitor) override;
private:
	MorisonPtr sharedFromThis();

	static int timesInstantiated;

	std::shared_ptr<Pile> pile;
	std::shared_ptr<Water> water;
	std::shared_ptr<WaveDynamic> waveDynamic;
};

#endif //MODEL_MORISON_H