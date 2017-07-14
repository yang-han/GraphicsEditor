#ifndef FILTER_COMMAND_H
#define FILTER_COMMAND_H

#include "command.h"
#include "ViewModel/viewmodel.h"
#include <string>
#include <memory>

class FilterRemCommand : public Command{
private:
    std::shared_ptr<ViewModel> viewmodel;
public:
    FilterRemCommand(std::shared_ptr<ViewModel> vm):viewmodel(vm){}
    ~FilterRemCommand(){}
    void exec();
};

#endif // FILTER_COMMAND_H
