#ifndef SAVE_FILE_COMMAND_H
#define SAVE_FILE_COMMAND_H
#include "command.h"
#include <memory>
#include <string>
class ViewModel;


class SaveFileCommand : public Command
{
private:
    std::shared_ptr<ViewModel> viewmodel;
public:
    SaveFileCommand(std::shared_ptr<ViewModel> vm);
    void exec();
};

#endif // SAVE_FILE_COMMAND_H
