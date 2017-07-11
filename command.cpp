#include "command.h"
#include "parameters.h"
#include "viewmodel.h"

Command::Command(std::shared_ptr<ViewModel> vm):viewmodel(vm)
{

}

Parameters& Command::get_params_handle(){
    return params;
}

//void Command::set_view_model(std::shared_ptr<ViewModel> viewmodel)
//{
//    this->viewmodel = viewmodel;
//}


