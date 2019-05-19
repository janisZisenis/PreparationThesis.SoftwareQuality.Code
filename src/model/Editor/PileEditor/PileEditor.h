#ifndef MODEL_PILEEDITOR_H
#define MODEL_PILEEDITOR_H

#include "model/Editor/Editor.h"

class Pile;

class PileEditor;
typedef std::shared_ptr<PileEditor> PileEditorPtr;
class model_EXPORT PileEditor : public Editor {
public:
	static PileEditorPtr getNewInstance(std::shared_ptr<Pile> node);
	virtual ~PileEditor();
private:
	PileEditor(std::shared_ptr<Pile> node);

public:
	virtual void editProperty(std::string propertyName, std::string propertyValue) override;
	std::string getPropertyValue(std::string propertyName) override;
private:
	std::shared_ptr<Pile> node	;
};


#endif //MODEL_PILEEDITOR_H