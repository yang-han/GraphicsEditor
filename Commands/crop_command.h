#ifndef CROP_COMMAND_H
#define CROP_COMMAND_H
#include"command.h"

class CropCommand:public Command
{
private:
	std::shared_ptr<ViewModel> viewmodel;
public:
    CropCommand(std::shared_ptr<ViewModel> vm) :viewmodel(vm) {}
	void exec();
};

#endif // CROP_COMMAND_H
