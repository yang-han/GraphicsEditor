#ifndef COMMAND_H
#define COMMAND_H
#include "parameters.h"
#include <string>
#include <memory>
#include "viewmodel.h"
class ViewModel;

class Command
{
protected:
    Parameters params;
    std::shared_ptr<ViewModel> viewmodel;
public:
    Command(std::shared_ptr<ViewModel> vm);
    Parameters& get_params_handle();
//    void set_view_model(std::shared_ptr<ViewModel> viewmodel);
    virtual void exec() = 0;
};

#endif // COMMAND_H
