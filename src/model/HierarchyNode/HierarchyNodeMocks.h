#ifndef MODEL_HIERARCHYNODEMOCKS_H
#define MODEL_HIERARCHYNODEMOCKS_H

#include "HierarchyNode.h"

class HierarchyNodeSubClass;
typedef shared_ptr<HierarchyNodeSubClass> HierarchyNodeSubClassPtr;
class HierarchyNodeSubClass : public HierarchyNode
{
public:
	static HierarchyNodeSubClassPtr getNewInstance()
	{
		return HierarchyNodeSubClassPtr(new HierarchyNodeSubClass());
	}
	virtual ~HierarchyNodeSubClass() {}
protected:
	HierarchyNodeSubClass() {}

public:
	virtual bool canBind(shared_ptr<HierarchyNode> node) override { return false; }
	virtual void accept(shared_ptr<Visitor> visitor) override {}
};

class HierarchyNodeDummy;
typedef shared_ptr<HierarchyNodeDummy> HierarchyNodeDummyPtr;
class HierarchyNodeDummy : public HierarchyNode
{
public:
	static HierarchyNodeDummyPtr getNewInstance()
	{
		return HierarchyNodeDummyPtr(new HierarchyNodeDummy());
	}
	virtual ~HierarchyNodeDummy() {}

protected:
	HierarchyNodeDummy() {}

public:
	virtual string getName() override { return ""; }
	virtual void setName(string name) override {}
	virtual string getType() override { return ""; }
	virtual bool canBind(shared_ptr<HierarchyNode> node) override { return false; }
	virtual void accept(shared_ptr<Visitor> visitor) override{}
};

class HierarchyNodeVisitorSpy;
typedef shared_ptr<HierarchyNodeVisitorSpy> HierarchyNodeVisitorSpyPtr;
class HierarchyNodeVisitorSpy : public HierarchyNodeDummy
{
public:
	static HierarchyNodeVisitorSpyPtr getNewInstance()
	{
		return HierarchyNodeVisitorSpyPtr(new HierarchyNodeVisitorSpy());
	}
	virtual ~HierarchyNodeVisitorSpy() {}
protected:
	HierarchyNodeVisitorSpy() {}

public:
	virtual void accept(shared_ptr<Visitor> visitor) override
	{
		this->acceptedVisitor = visitor;
	}
	virtual shared_ptr<Visitor> getAcceptedVisitor()
	{
		return this->acceptedVisitor;
	}

private:
	shared_ptr<Visitor> acceptedVisitor;
};

class HierarchyNodeCanBindSpy;
typedef shared_ptr<HierarchyNodeCanBindSpy> HierarchyNodeCanBindSpyPtr;
class HierarchyNodeCanBindSpy : public HierarchyNodeDummy
{
public:
	static HierarchyNodeCanBindSpyPtr getNewInstance()
	{
		return HierarchyNodeCanBindSpyPtr(new HierarchyNodeCanBindSpy());
	}
	virtual ~HierarchyNodeCanBindSpy() {}
protected:
	HierarchyNodeCanBindSpy() {}
public:
	virtual bool canBind(HierarchyNodePtr node)
	{
		this->iWasAskedIfCanBindNode = true;
		return HierarchyNodeDummy::canBind(node);
	}
	virtual bool wasAskedIfCanBindNode()
	{
		return this->iWasAskedIfCanBindNode;
	}
private:
	bool iWasAskedIfCanBindNode = false;
};

class NodeReturnsInvalidTypeStub;
typedef shared_ptr<NodeReturnsInvalidTypeStub> NodeReturnsInvalidTypeStubPtr;
class NodeReturnsInvalidTypeStub : public HierarchyNodeDummy
{
public:
	static NodeReturnsInvalidTypeStubPtr getNewInstance()
	{
		return NodeReturnsInvalidTypeStubPtr(new NodeReturnsInvalidTypeStub());
	}
	virtual ~NodeReturnsInvalidTypeStub() {}
protected:
	NodeReturnsInvalidTypeStub() {}
public:
	virtual string getType() override
	{
		return "invalidType";
	}
};

class ReturnsASpecificTypeStub;
typedef shared_ptr<ReturnsASpecificTypeStub> ReturnsASpecificTypeStubPtr;
class ReturnsASpecificTypeStub : public HierarchyNodeDummy
{
public:
	static ReturnsASpecificTypeStubPtr getNewInstance(string type)
	{
		return ReturnsASpecificTypeStubPtr(new ReturnsASpecificTypeStub(type));
	}
	virtual ~ReturnsASpecificTypeStub() {}
protected:
	ReturnsASpecificTypeStub(string type)
	{
		this->stubType = type;
	}

public:
	virtual string getType() override
	{
		return stubType;
	}
	string stubType;
};

class ReturnsASpecificNameStub;
typedef shared_ptr<ReturnsASpecificNameStub> ReturnsASpecificNameStubPtr;
class ReturnsASpecificNameStub : public HierarchyNodeDummy
{
public:
	static ReturnsASpecificNameStubPtr getNewInstance(string name)
	{
		return ReturnsASpecificNameStubPtr(new ReturnsASpecificNameStub(name));
	}
	virtual ~ReturnsASpecificNameStub() {}
protected:
	ReturnsASpecificNameStub(string name)
	{
		this->stubName = name;
	}

public:
	virtual string getName() override
	{
		return stubName;
	}
	string stubName;
};

class CanBindNodeStub;
typedef shared_ptr<CanBindNodeStub> CanBindNodeStubPtr;
class CanBindNodeStub : public ReturnsASpecificNameStub
{
public:
	static CanBindNodeStubPtr getNewInstance(string name)
	{
		return CanBindNodeStubPtr(new CanBindNodeStub(name));
	}
	virtual ~CanBindNodeStub() {}
protected:
	CanBindNodeStub(string name) : ReturnsASpecificNameStub(name) {}

public:
	virtual bool canBind(shared_ptr<HierarchyNode> node) override { return true; }
};

class CanNotBindNodeStub;
typedef shared_ptr<CanNotBindNodeStub> CanNotBindNodeStubPtr;
class CanNotBindNodeStub : public ReturnsASpecificNameStub
{
public:
	static CanNotBindNodeStubPtr getNewInstance(string name)
	{
		return CanNotBindNodeStubPtr(new CanNotBindNodeStub(name));
	}
	virtual ~CanNotBindNodeStub() {}
protected:
	CanNotBindNodeStub(string name) : ReturnsASpecificNameStub(name) {}

public:
	virtual bool canBind(shared_ptr<HierarchyNode> node) override { return false; }
};

#endif //MODEL_HIERARCHYNODEMOCKS_H