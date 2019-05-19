#pragma once
#include <model/model_Export.h>
#include <utilities/CommandQueue/Command.h>
#include <utilities/Object/Object.h>

class Editor;

class EditCommand;
typedef std::shared_ptr<EditCommand> EditCommandPtr;
class model_EXPORT EditCommand : public Command , public Object {
public:
	static EditCommandPtr getNewInstance(std::shared_ptr<Editor> node,
										 std::string propertyName,
										 std::string propertyValue);
	virtual ~EditCommand();
private:
	EditCommand(std::shared_ptr<Editor> node,
				std::string propertyName,
				std::string propertyValue);

public:
	virtual void execute() override;
	virtual void undo() override;
	virtual void redo() override;

private:
	std::shared_ptr<Editor> editor;
	std::string propertyName;
	std::string exePropertyValue;
	std::string undoPropertyValue;
};