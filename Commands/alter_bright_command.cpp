#include "alter_bright_command.h"
#include "viewmodel.h"
#include "command.h"
#include <QDebug>
#include <string>


void AlterBrightCommand::exec(){
    int nBright = std::static_pointer_cast<brightParameters, Parameters>(Command::params)->get_nBright();
    viewmodel->exec_alter_bright_command(nBright);
}


