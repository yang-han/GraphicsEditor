#include "app.h"
#include "view.h"
#include "viewmodel.h"
#include "model.h"
#include "command.h"
#include "Commands/open_file_command.h"
#include "Commands/alter_bright_command.h"
#include "notification.h"
#include <memory>

App::App():view(new View),model(new Model), viewmodel(new ViewModel)
{

    viewmodel->bind(model);

    view->set_img(viewmodel->get());

    view->set_open_file_command(viewmodel->get_open_file_command());
    view->set_alter_bright_command(viewmodel->get_alter_bright_command());
    view->set_filter_rem_command(viewmodel->get_filter_rem_command());

    viewmodel->set_update_view_notification(view->get_update_view_notification());
    model->set_update_display_data_notification(viewmodel->get_update_display_data_notification());

}

void App::run(){
    view->show();
}
