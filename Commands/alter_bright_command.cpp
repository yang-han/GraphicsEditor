#include "Commands/alter_bright_command.h"
#include "ViewModel/viewmodel.h"
#include "Commands/command.h"
#include <QDebug>
#include <string>


void AlterBrightCommand::exec(){
    int nBright = std::static_pointer_cast<brightAndContrastParameters, Parameters>(Command::params)->get_nBright();
    int nContrast = std::static_pointer_cast<brightAndContrastParameters, Parameters>(Command::params)->get_nContrast();
    viewmodel->exec_alter_bright_command(nBright,nContrast);
}


