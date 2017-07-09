#include "command.h"
#include "viewmodel.h"
#include <string>
class OpenFileCommand : public Command
{

public:
    OpenFileCommand(std::shared_ptr<ViewModel> vm, std::string path):Command(vm) {
        Command::params.set_path(path);
    }
    void exec();
};
