#include "app.h"
#include "view.h"
#include "viewmodel.h"
#include "model.h"
#include "command.h"
#include "notification.h"
#include <memory>

App::App():view(new View),model(new Model), viewmodel(new ViewModel)
{

    viewmodel->bind(model);

    view->set_img(viewmodel->get());

    view->set_open_file_command(viewmodel->get_open_file_command());
    view->set_alter_bright_command(viewmodel->get_alter_bright_command());
    view->set_filter_rem_command(viewmodel->get_filter_rem_command());
    view->set_reset_command(viewmodel->get_reset_command());
    view->set_detect_face_command(viewmodel->get_detect_face_command());
    view->set_save_file_command(viewmodel->get_save_file_command());
    view->set_save_bmp_file_command(viewmodel->get_save_bmp_file_command());
    view->set_rotate_command(viewmodel->get_rotate_command());
    view->set_crop_command(viewmodel->get_crop_command());

    viewmodel->set_update_view_notification(view->get_update_view_notification());
    model->set_update_display_data_notification(viewmodel->get_update_display_data_notification());

}

void App::run(){
    view->show();
}
