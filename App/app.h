#ifndef APP_H
#define APP_H

#include <memory>

class ViewModel;
class View;
class Model;
class Notification;
class OpenFileCommand;
class AlterBrightCommand;

class App
{
private:
    std::shared_ptr<View> view;
    std::shared_ptr<Model> model;
    std::shared_ptr<ViewModel> viewmodel;

public:
    App();
    void run();
};

#endif // APP_H
