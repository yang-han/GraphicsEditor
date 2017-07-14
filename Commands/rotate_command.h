#ifndef ROTATE_COMMAND_H
#define ROTATE_COMMAND_H

#include "command.h"
#include "ViewModel/viewmodel.h"
#include <string>
#include <memory>

class RotateCommand : public Command{
private:
    std::shared_ptr<ViewModel> viewmodel;
public:
    RotateCommand(std::shared_ptr<ViewModel> vm):viewmodel(vm){}
    ~RotateCommand(){}
    void exec();
};


#endif // ROTATE_COMMAND_H
