#include "Commands/open_file_command.h"
#include "viewmodel.h"
#include "command.h"
#include <QDebug>


OpenFileCommand::OpenFileCommand(std::shared_ptr<ViewModel> vm):Command(vm){

}

void OpenFileCommand::exec(){
//    qInfo() << QString("exec");
    viewmodel->exec_open_file_command(Command::params);

//    qInfo() << QString("exec");
}

OpenFileCommand::~OpenFileCommand(){}
