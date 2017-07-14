#include "aeroglass.h"
#include "viewmodel.h"
#include "command.h"
#include <QDebug>
#include <string>

void AeroGlassCommand::exec(){
    viewmodel->exec_Aero_Glass_command();
}
