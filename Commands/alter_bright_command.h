#ifndef ALTER_BRIGHT_COMMAND_H
#define ALTER_BRIGHT_COMMAND_H


#include "command.h"
#include "ViewModel/viewmodel.h"
#include <memory>

class AlterBrightCommand : public Command{
private:
    std::shared_ptr<ViewModel> viewmodel;
public:
    AlterBrightCommand(std::shared_ptr<ViewModel> vm):viewmodel(vm){}
//    ~AlterBrightCommand(){}
    void exec();

};

#endif // ALTER_BRIGHT_COMMAND_H
