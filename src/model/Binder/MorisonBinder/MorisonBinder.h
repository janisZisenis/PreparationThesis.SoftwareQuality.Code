#ifndef MODEL_MORISONBINDER_H
#define MODEL_MORISONBINDER_H

#include <model/model_Export.h>
#include <utilities/Visitor/Visitor.h>
#include <utilities/Object/Object.h>

class Morison;

class MorisonBinder;
typedef std::shared_ptr<MorisonBinder> MorisonBinderPtr;

class model_EXPORT MorisonBinder : public Visitor, public Object {
public:
	static MorisonBinderPtr getNewInstance(std::shared_ptr<Morison> node);
	virtual ~MorisonBinder();
protected:
	MorisonBinder(std::shared_ptr<Morison> node);
private:
	std::shared_ptr<Morison> child;
	bool alreadyVisited = false;
};

#endif //MODEL_MORISONBINDER_H