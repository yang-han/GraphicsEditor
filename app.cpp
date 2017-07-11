#include "app.h"
#include "view.h"
#include "viewmodel.h"
#include "model.h"
#include "command.h"
#include "Commands/open_file_command.h"
#include "notification.h"
#include <memory>

App::App():view(new View),model(new Model), viewmodel(new ViewModel)
{

    viewmodel->bind(model);

    view->set_img(viewmodel->get());

    view->set_open_file_command(viewmodel->get_open_file_command());

    viewmodel->set_notification(std::shared_ptr<ViewModelNotification>(new ViewModelNotification(view)));
    model->set_notification(std::shared_ptr<ModelNotification>(new ModelNotification(viewmodel)));


}

void App::run(){
    view->show();
}
