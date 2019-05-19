#ifndef MODEL_WAVEEDITOR_H
#define MODEL_WAVEEDITOR_H

#include "model/Editor/Editor.h"

class Wave;

class WaveEditor;
typedef std::shared_ptr<WaveEditor> WaveEditorPtr;
class model_EXPORT WaveEditor : public Editor {
public:
	static WaveEditorPtr getNewInstance(std::shared_ptr<Wave> node);
	virtual ~WaveEditor();
private:
	WaveEditor(std::shared_ptr<Wave> node);

public:
	virtual void editProperty(std::string propertyName, std::string propertyValue) override;
	std::string getPropertyValue(std::string propertyName) override;
private:
	std::shared_ptr<Wave> node;
};

#endif //MODEL_WAVEEDITOR_H