#ifndef MODEL_EDITOR_H
#define MODEL_EDITOR_H

#include <model/model_Export.h>
#include <utilities/Object/Object.h>

class HierarchyNode;

class Editor;
typedef std::shared_ptr<Editor> EditorPtr;

class model_EXPORT Editor : public Object {
public:
    virtual ~Editor();
protected:
	Editor();

public:
	virtual void editProperty(std::string propertyName, std::string propertyValue) = 0;
	virtual std::string getPropertyValue(std::string propertyName) = 0;
protected:
    virtual void editName(std::shared_ptr<HierarchyNode> node, std::string propertyValue);
	virtual void throwInvalidPropertyException();
	virtual double convertToDouble(std::string s);
};

class InvalidPropertyException : public std::exception {
public:
	virtual const char *what() const throw();
};


class InvalidPropertyFormatException : public std::exception {
    virtual const char *what() const throw();
};

#endif //MODEL_EDITOR_H