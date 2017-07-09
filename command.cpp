#include "command.h"
#include "viewmodel.h"
#include "parameters.h"
Command::Command()
{

}


void Command::bind(std::shared_ptr<ViewModel> viewmodel){
    this->viewmodel = viewmodel;
}

Parameters& Command::get_params(){
    return params;
}


void Command::set_type(Type t){type = t;}
