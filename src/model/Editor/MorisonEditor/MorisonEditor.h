#ifndef MODEL_MORISONEDITOR_H
#define MODEL_MORISONEDITOR_H

#include "model/Editor/Editor.h"

class Morison;

class MorisonEditor;
typedef std::shared_ptr<MorisonEditor> MorisonEditorPtr;
class model_EXPORT MorisonEditor : public Editor {
public:
    static MorisonEditorPtr getNewInstance(std::shared_ptr<Morison> node);
    virtual ~MorisonEditor();
private:
    MorisonEditor(std::shared_ptr<Morison> node);

public:
    virtual void editProperty(std::string propertyName, std::string propertyValue) override;
    std::string getPropertyValue(std::string propertyName) override;

private:
    std::shared_ptr<Morison> node;
};


#endif //MODEL_MORISONEDITOR_H