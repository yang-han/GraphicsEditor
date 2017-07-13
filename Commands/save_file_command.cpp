#include "save_file_command.h"
#include "viewmodel.h"

SaveFileCommand::SaveFileCommand(std::shared_ptr<ViewModel> vm):viewmodel(vm){

}

void SaveFileCommand::exec()
{
    std::string path = std::static_pointer_cast<PathParameters, Parameters>(Command::params)->get_path();
    viewmodel->exec_save_file_command(path);
}
