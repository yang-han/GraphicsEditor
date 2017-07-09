#ifndef APP_H
#define APP_H
#include "common.h"
#include "view.h"
#include "viewmodel.h"
#include "model.h"
#include "Commands/open_file_command.h"
class Model;

class App
{
private:
    std::shared_ptr<Model> model;
    std::shared_ptr<ViewModel> viewmodel;
    std::shared_ptr<View> view;
    std::shared_ptr<Notification> notification;
    std::shared_ptr<OpenFileCommand> open_file_command;

public:
    App();
    ~App();
    void run();
};

#endif // APP_H
