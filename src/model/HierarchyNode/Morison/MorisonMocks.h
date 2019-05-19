#ifndef MODEL_MORISONMOCKS_H
#define MODEL_MORISONMOCKS_H

#include "Morison.h"

class MorisonSubClass;
typedef shared_ptr<MorisonSubClass> MorisonSubClassPtr;
class MorisonSubClass : public Morison
{
public:
	static MorisonSubClassPtr getNewInstance()
	{
		return MorisonSubClassPtr(new MorisonSubClass());
	}
	virtual ~MorisonSubClass() {}
protected:
	MorisonSubClass() : Morison() {}
};

class MorisonReturnsNullptrForChilds;
typedef shared_ptr<MorisonReturnsNullptrForChilds> MorisonReturnsNullptrForChildsPtr;
class MorisonReturnsNullptrForChilds : public MorisonSubClass
{
public:
	static MorisonReturnsNullptrForChildsPtr getNewInstance()
	{
		return MorisonReturnsNullptrForChildsPtr(new MorisonReturnsNullptrForChilds());
	}
	virtual ~MorisonReturnsNullptrForChilds() {}
protected:
	MorisonReturnsNullptrForChilds() : MorisonSubClass() {}

public:
	virtual HierarchyNodePtr getWaveDynamic() override
	{
		return nullptr;
	}
	virtual HierarchyNodePtr getPile() override
	{
		return nullptr;
	}
};


#endif //MODEL_MORISONMOCKS_H