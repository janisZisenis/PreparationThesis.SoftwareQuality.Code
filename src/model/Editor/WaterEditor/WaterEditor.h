#ifndef MODEL_WATERDYNAMICEDITOR_H
#define MODEL_WATERDYNAMICEDITOR_H

#include "model/Editor/Editor.h"

class Water;

class WaterEditor;
typedef std::shared_ptr<WaterEditor> WaterEditorPtr;
class model_EXPORT WaterEditor : public Editor {
public:
	static WaterEditorPtr getNewInstance(std::shared_ptr<Water> node);
	virtual ~WaterEditor();
private:
	WaterEditor(std::shared_ptr<Water> node);

public:
	virtual void editProperty(std::string propertyName, std::string propertyValue) override;
	std::string getPropertyValue(std::string propertyName) override;
private:
	std::shared_ptr<Water> node	;
};

#endif //MODEL_WATERDYNAMICEDITOR_H