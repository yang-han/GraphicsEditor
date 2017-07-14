#include "aeroglass.h"
#include "ViewModel/viewmodel.h"
#include "Commands/command.h"
#include <QDebug>
#include <string>

void AeroGlassCommand::exec(){
    viewmodel->exec_Aero_Glass_command();
}
