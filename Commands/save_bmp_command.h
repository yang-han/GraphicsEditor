#ifndef SAVE_BMP_COMMAND_H
#define SAVE_BMP_COMMAND_H
#include "command.h"
#include <memory>
#include <string>

class ViewModel;


class SaveBmpCommand : public Command
{
private:
    std::shared_ptr<ViewModel> viewmodel;
public:
    SaveBmpCommand(std::shared_ptr<ViewModel> vm);
    void exec();
};
#endif // SAVE_BMP_COMMAND_H
