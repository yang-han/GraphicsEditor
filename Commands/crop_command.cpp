#include "crop_command.h"

void CropCommand::exec(){
    double x1 = std::static_pointer_cast<MouseMoveParameters, Parameters>(Command::params)->getx_s();
    double y1 = std::static_pointer_cast<MouseMoveParameters, Parameters>(Command::params)->gety_s();
    double x2 = std::static_pointer_cast<MouseMoveParameters, Parameters>(Command::params)->getx_e();
    double y2 = std::static_pointer_cast<MouseMoveParameters, Parameters>(Command::params)->gety_e();

    viewmodel->exec_crop_command(x1,y1,x2,y2);
}
