#ifndef COMMAND_H
#define COMMAND_H

#include "common.h"
#include "parameters.h"
class ViewModel;

class Command
{
protected:
    std::shared_ptr<ViewModel> viewmodel;
    Type type;
    Parameters params;


public:
    Command();
    void bind(std::shared_ptr<ViewModel> viewmodel);
    void set_type(Type t);
    Parameters& get_params();
    virtual void exec() = 0;
};

#endif // COMMAND_H
