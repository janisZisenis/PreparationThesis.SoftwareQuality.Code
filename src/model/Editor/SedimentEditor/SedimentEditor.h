#ifndef MODEL_SEDIMENTEDITOR_H
#define MODEL_SEDIMENTEDITOR_H

#include "model/Editor/Editor.h"

class Sediment;

class SedimentEditor;
typedef std::shared_ptr<SedimentEditor> SedimentEditorPtr;
class model_EXPORT SedimentEditor : public Editor {
public:
	static SedimentEditorPtr getNewInstance(std::shared_ptr<Sediment> node);
	virtual ~SedimentEditor();
private:
	SedimentEditor(std::shared_ptr<Sediment> node);

public:
	virtual void editProperty(std::string propertyName, std::string propertyValue) override;
	std::string getPropertyValue(std::string propertyName) override;
private:
	std::shared_ptr<Sediment> node	;
};

#endif //MODEL_SEDIMENTEDITOR_H