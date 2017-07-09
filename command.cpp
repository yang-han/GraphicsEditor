#include "command.h"
#include "viewmodel.h"
Command::Command(std::shared_ptr<ViewModel> vm):viewmodel(vm)
{

}


void Command::set_type(Type t){type = t;}
