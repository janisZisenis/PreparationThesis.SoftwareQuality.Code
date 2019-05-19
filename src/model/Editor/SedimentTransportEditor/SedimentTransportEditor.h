#ifndef MODEL_SEDIMENTTRANSPORTEDITOR_H
#define MODEL_SEDIMENTTRANSPORTEDITOR_H

#include "model/Editor/Editor.h"

class SedimentTransport;

class SedimentTransportEditor;
typedef std::shared_ptr<SedimentTransportEditor> SedimentTransportEditorPtr;
class model_EXPORT SedimentTransportEditor : public Editor {
public:
	static SedimentTransportEditorPtr getNewInstance(std::shared_ptr<SedimentTransport> node);
	virtual ~SedimentTransportEditor();
private:
	SedimentTransportEditor(std::shared_ptr<SedimentTransport> node);

public:
	virtual void editProperty(std::string propertyName, std::string propertyValue) override;
	std::string getPropertyValue(std::string propertyName) override;
private:
	std::shared_ptr<SedimentTransport> node	;
};

#endif //MODEL_SEDIMENTTRANSPORTEDITOR_H