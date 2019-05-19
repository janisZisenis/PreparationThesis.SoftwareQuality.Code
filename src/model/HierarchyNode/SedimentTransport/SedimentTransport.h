#ifndef MODEL_SEDIMENTTRANSPORT_H
#define MODEL_SEDIMENTTRANSPORT_H

#include "model/HierarchyNode/HierarchyNode.h"

class WaveDynamic;
class Sediment;
class Water;

class SedimentTransport;
typedef std::shared_ptr<SedimentTransport> SedimentTransportPtr;
class model_EXPORT SedimentTransport : public HierarchyNode {
public:
	static SedimentTransportPtr getNewInstance();
	virtual ~SedimentTransport();
protected:
	SedimentTransport();

public:
	virtual bool canBind(HierarchyNodePtr node) override;

	virtual void setWater(std::shared_ptr<Water> water);
	virtual std::shared_ptr<Water> getWater();
	virtual void setWaveDynamic(std::shared_ptr<WaveDynamic> waveDynamic);
	virtual std::shared_ptr<WaveDynamic> getWaveDynamic();
	virtual void setSediment(std::shared_ptr<Sediment> sediment);
	virtual std::shared_ptr<Sediment> getSediment();

	virtual std::shared_ptr<Visitor> makeBinder() override;
	virtual std::shared_ptr<Editor> makeEditor() override;
	virtual void accept(std::shared_ptr<Visitor> visitor) override;
private:
	SedimentTransportPtr sharedFromThis();

	static int timesInstantiated;

	std::shared_ptr<WaveDynamic> waveDynamic;
    std::shared_ptr<Sediment> sediment;
    std::shared_ptr<Water> water;
};

#endif //MODEL_SEDIMENTTRANSPORT_H