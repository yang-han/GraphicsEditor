#include "save_bmp_command.h"
#include "ViewModel/viewmodel.h"

SaveBmpCommand::SaveBmpCommand(std::shared_ptr<ViewModel> vm):viewmodel(vm){

}

void SaveBmpCommand::exec()
{
    std::string path = std::static_pointer_cast<PathParameters, Parameters>(Command::params)->get_path();
    viewmodel->exec_save_bmp_file_command(path);
}
