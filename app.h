#ifndef APP_H
#define APP_H
#include "common.h"

App::App()
{
private:
    std::shared_ptr<Model> model;
    std::shared_ptr<ViewModel> viewmodel;
    std::shared_ptr<View> view;

public:
    App();
    ~APP();

}

#endif // APP_H
