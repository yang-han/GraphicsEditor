#include "rotate_command.h"

void RotateCommand::exec(){
    int angle = std::static_pointer_cast<IntParameters, Parameters>(Command::params)->getvalue();
    viewmodel->exec_rotate_command(angle);
}
