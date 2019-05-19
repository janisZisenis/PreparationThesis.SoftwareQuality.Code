#include "EditCommand.h"
#include <model/Editor/Editor.h>

EditCommandPtr EditCommand::getNewInstance(EditorPtr editor, std::string propertyName, std::string propertyValue) {
    return EditCommandPtr(new EditCommand(editor, propertyName, propertyValue));
}

EditCommand::~EditCommand() {}

EditCommand::EditCommand(EditorPtr editor, std::string propertyName, std::string propertyValue)
		: editor(editor), propertyName(propertyName), exePropertyValue(propertyValue),
		  undoPropertyValue(editor->getPropertyValue(propertyName)) {}

void EditCommand::execute() {
	try{
		editor->editProperty(propertyName, exePropertyValue);
	}
	catch (std::exception *e) {
		throw new CommandException();
	}
}

void EditCommand::undo() {
	editor->editProperty(propertyName, undoPropertyValue);
}

void EditCommand::redo() {
	execute();
}
