#ifndef MODEL_WAVEDYNAMICEDITOR_H
#define MODEL_WAVEDYNAMICEDITOR_H

#include "model/Editor/Editor.h"

class WaveDynamic;

class WaveDynamicEditor;
typedef std::shared_ptr<WaveDynamicEditor> WaveDynamicEditorPtr;
class model_EXPORT WaveDynamicEditor : public Editor {
public:
	static WaveDynamicEditorPtr getNewInstance(std::shared_ptr<WaveDynamic> node);
	virtual ~WaveDynamicEditor();
private:
	WaveDynamicEditor(std::shared_ptr<WaveDynamic> node);

public:
	virtual void editProperty(std::string propertyName, std::string propertyValue) override;
	std::string getPropertyValue(std::string propertyName) override;
private:
	std::shared_ptr<WaveDynamic> node	;
};

#endif //MODEL_WAVEDYNAMICEDITOR_H