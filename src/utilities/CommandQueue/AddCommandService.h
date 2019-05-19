#ifndef UTILITIES_ADDCOMMANDSERVICE_H
#define UTILITIES_ADDCOMMANDSERVICE_H

#include <memory>

class Command;

class AddCommandService;
typedef std::shared_ptr<AddCommandService> AddCommandServicePtr;
class AddCommandService {
public:
    ~AddCommandService() {};
protected:
    AddCommandService() {};
public:
	virtual void add(std::shared_ptr<Command> command) = 0;
};

#endif //UTILITIES_ADDCOMMANDSERVICE_H