#include "Commands/open_file_command.h"
#include "viewmodel.h"
#include "command.h"

OpenFileCommand::OpenFileCommand(){

}

void OpenFileCommand::exec(){
    viewmodel->exec_open_file_command(Command::params);
}

OpenFileCommand::~OpenFileCommand(){}
