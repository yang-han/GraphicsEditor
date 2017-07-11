#ifndef _OPEN_FILE_COMMAND_H_
#define _OPEN_FILE_COMMAND_H_

#include "command.h"
#include "viewmodel.h"
#include <string>
#include <memory>

class OpenFileCommand : public Command{
public:
    OpenFileCommand(std::shared_ptr<ViewModel> vm);
    ~OpenFileCommand();
    void exec();

};

#endif
