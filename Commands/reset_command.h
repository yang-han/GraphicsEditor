#ifndef RESET_H_
#define RESET_H_
#include "command.h"
#include "viewmodel.h"
#include <string>
#include <memory>

class ResetCommand : public Command {
private:
	std::shared_ptr<ViewModel> viewmodel;
public:
	ResetCommand(std::shared_ptr<ViewModel> vm) :viewmodel(vm) {}
	~ResetCommand() {}
	void exec();
};
#endif // !RESET_H_

