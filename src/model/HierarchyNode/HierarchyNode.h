#ifndef MODEL_HIERARCHYNODE_H
#define MODEL_HIERARCHYNODE_H

#include <model/model_Export.h>
#include "utilities/Object/Object.h"
#include <boost/signals2/signal.hpp>
#include <utilities/Visitor/Visitable.h>

class Visitor;
class Editor;

class HierarchyNode;
typedef std::shared_ptr <HierarchyNode> HierarchyNodePtr;
class model_EXPORT HierarchyNode : public Object, public Visitable {
public:
    virtual ~HierarchyNode();
protected:
    HierarchyNode(std::string name, std::string type);

public: //signals
	boost::signals2::signal<void(const HierarchyNodePtr inserted, const int index)> childInserted;
	boost::signals2::signal<void (const HierarchyNodePtr removed, const int index)> childRemoved;
    boost::signals2::signal<void (const HierarchyNodePtr replaced, const std::string type)> childReplaced;
    boost::signals2::signal<void (const HierarchyNodePtr emiting)> nodeChanged;
protected: //slots
    virtual void onNodeChanged(const std::shared_ptr<HierarchyNode> changed);
public:
    virtual std::string getName() const;
    virtual std::string getType() const;
    virtual void setName(std::string name);

    virtual bool canBind(HierarchyNodePtr node);

    virtual std::shared_ptr<Visitor> makeBinder();
    virtual std::shared_ptr<Editor> makeEditor();
    void accept(std::shared_ptr<Visitor> visitor) override;
private:
    HierarchyNodePtr sharedFromThis();

protected:
    void connectToNode(std::shared_ptr<HierarchyNode> node);
    void disconnectFromNode(std::shared_ptr<HierarchyNode> node);

    void initializeName(int timesInstantiated);

    std::string name;
    std::string type;
};

class NoBinderException : public std::exception {
    const char *what() const throw() override;
};


#endif //MODEL_HIERARCHYNODE_H