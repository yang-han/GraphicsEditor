#ifndef _OPEN_FILE_COMMAND_H_
#define _OPEN_FILE_COMMAND_H_

#include "command.h"
#include "ViewModel/viewmodel.h"
#include <string>
#include <memory>

class OpenFileCommand : public Command{
private:
    std::shared_ptr<ViewModel> viewmodel;
public:
    OpenFileCommand(std::shared_ptr<ViewModel> vm);
    ~OpenFileCommand();
    void exec();

};

#endif
