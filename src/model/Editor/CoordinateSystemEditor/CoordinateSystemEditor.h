#ifndef MODEL_COORDINATESYSTEMEDITOR_H
#define MODEL_COORDINATESYSTEMEDITOR_H

#include "model/Editor/Editor.h"

class CoordinateSystem;

class CoordinateSystemEditor;
typedef std::shared_ptr<CoordinateSystemEditor> CoordinateSystemEditorPtr;
class model_EXPORT CoordinateSystemEditor : public Editor {
public:
	static CoordinateSystemEditorPtr getNewInstance(std::shared_ptr<CoordinateSystem> node);
	virtual ~CoordinateSystemEditor();
private:
	CoordinateSystemEditor(std::shared_ptr<CoordinateSystem> node);

public:
	virtual void editProperty(std::string propertyName, std::string propertyValue) override;
	virtual std::string getPropertyValue(std::string propertyName) override;

private:
	std::shared_ptr<CoordinateSystem> node	;
};


#endif //MODEL_COORDINATESYSTEMEDITOR_H