#ifndef MODEL_WAVEDYNAMICMOCKS_H
#define MODEL_WAVEDYNAMICMOCKS_H

#include "WaveDynamic.h"

class WaveDynamicSubClass;
typedef shared_ptr<WaveDynamicSubClass> WaveDynamicSubClassPtr;
class WaveDynamicSubClass : public WaveDynamic
{
public:
	static WaveDynamicSubClassPtr getNewInstance()
	{
		return WaveDynamicSubClassPtr(new WaveDynamicSubClass());
	}
	virtual ~WaveDynamicSubClass() {}
protected:
	WaveDynamicSubClass() : WaveDynamic() {}
};

class WaveDynamicSubClassPropertiesStub;
typedef shared_ptr<WaveDynamicSubClassPropertiesStub> WaveDynamicSubClassPropertiesStubPtr;
class WaveDynamicSubClassPropertiesStub : public WaveDynamicSubClass
{
public:
	static WaveDynamicSubClassPropertiesStubPtr getNewInstance()
	{
		return WaveDynamicSubClassPropertiesStubPtr(new WaveDynamicSubClassPropertiesStub());
	};
	virtual ~WaveDynamicSubClassPropertiesStub() {};
protected:
	WaveDynamicSubClassPropertiesStub() : WaveDynamicSubClass() {};

public:
	virtual void setProperties(string name)
	{
		this->stubName = name;
	}

	virtual string getName() override
	{
		return this->stubName;
	}

private:
	string stubName;
};

class WaveDynamicReturnsNullptrForChilds;
typedef shared_ptr<WaveDynamicReturnsNullptrForChilds> WaveDynamicReturnsNullptrForChildsPtr;
class WaveDynamicReturnsNullptrForChilds : public WaveDynamicSubClass
{
public:
	static WaveDynamicReturnsNullptrForChildsPtr getNewInstance()
	{
		return WaveDynamicReturnsNullptrForChildsPtr(new WaveDynamicReturnsNullptrForChilds());
	}
	virtual ~WaveDynamicReturnsNullptrForChilds() {}
protected:
	WaveDynamicReturnsNullptrForChilds() : WaveDynamicSubClass() {}

public:
	virtual HierarchyNodePtr getCoordinateSystem() override
	{
		return nullptr;
	}
	virtual HierarchyNodePtr getWater() override
	{
		return nullptr;
	}
	virtual HierarchyNodePtr getWave() override
	{
		return nullptr;
	}
};

#endif //MODEL_WAVEDYNAMICMOCKS_H