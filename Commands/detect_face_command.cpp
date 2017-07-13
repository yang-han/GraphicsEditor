#include "detect_face_command.h"

DetectFaceCommand::DetectFaceCommand(std::shared_ptr<ViewModel> vm):viewmodel(vm)
{

}
void DetectFaceCommand::exec(){
    viewmodel->exec_detect_face_command();
}
