#ifndef DETECT_FACE_COMMAND_H
#define DETECT_FACE_COMMAND_H
#include "command.h"
class ViewModel;



class DetectFaceCommand : public Command
{

private:
    std::shared_ptr<ViewModel> viewmodel;
public:
    DetectFaceCommand(std::shared_ptr<ViewModel> vm);
    void exec();
};

#endif // DETECT_FACE_COMMAND_H
