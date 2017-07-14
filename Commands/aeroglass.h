#ifndef AEROGLASS_H
#define AEROGLASS_H

#include "command.h"
#include "ViewModel/viewmodel.h"
#include <string>
#include <memory>

class AeroGlassCommand : public Command{
private:
    std::shared_ptr<ViewModel> viewmodel;
public:
    AeroGlassCommand(std::shared_ptr<ViewModel> vm):viewmodel(vm){}
    ~AeroGlassCommand(){}
    void exec();
};




#endif // AEROGLASS_H
