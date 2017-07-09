#include "app.h"
#include "common.h"
#include "view.h"
#include "model.h"
#include "viewmodel.h"
#include "notification.h"
#include "Commands/open_file_command.h"

App::App():
model(new Model), viewmodel(new ViewModel), view(new View)
{
    viewmodel->bind(model, notification);
    model->bind(viewmodel);
    notification->bind(view, viewmodel);
    open_file_command->bind(viewmodel);
    view->setOpenFileCommand(open_file_command);
}

App::~App(){
//    delete model;
//    delete viewmodel;
//    delete view;
}

void App::run(){
    view->show();
}
