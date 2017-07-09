#ifndef COMMAND_H
#define COMMAND_H

#include "common.h"
#include "parameters.h"
#include "viewmodel.h"

class Command
{
protected:
    std::shared_ptr<ViewModel> viewmodel;
    Type type;
    Parameters params;


public:
    Command();
    void set_type(Type t);
    virtual exec() = 0;
};

#endif // COMMAND_H
