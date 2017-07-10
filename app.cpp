#include "app.h"
#include "view.h"
#include "viewmodel.h"
#include "model.h"
#include "command.h"
#include "Commands/open_file_command.h"
#include "notification.h"
#include <memory>

App::App():view(new View),model(new Model), viewmodel(new ViewModel),
    notification(new Notification), open_file_command(new OpenFileCommand)
{

    viewmodel->bind(model);
    model->bind(viewmodel);
    notification->bind(viewmodel, view);
    viewmodel->set_notification(notification);
    open_file_command->set_view_model(viewmodel);

    view->set_open_file_command(open_file_command);
}

void App::run(){
    view->show();
}
