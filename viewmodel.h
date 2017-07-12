#ifndef VIEWMODEL_H
#define VIEWMODEL_H
#include <QImage>
#include <memory>
#include "parameters.h"
#include "command.h"

class Model;
class Notification;
class ViewModelNotification;
class Command;

class ViewModel
{
private:
    std::shared_ptr<QImage> q_image;
    std::shared_ptr<Model> model;
    std::shared_ptr<ViewModelNotification> viewmodel_notification;


    std::shared_ptr<Command> open_file_command;

    std::shared_ptr<Notification> update_display_data_notification;

    std::shared_ptr<Notification> update_view_notification;

public:
    ViewModel();
    void bind(std::shared_ptr<Model> model);
    void set_notification(std::shared_ptr<ViewModelNotification> notification);
    void exec_open_file_command(Parameters params);

    void set_update_view_notification(std::shared_ptr<Notification> notification);

    std::shared_ptr<Command> get_open_file_command();
    std::shared_ptr<Notification> get_update_display_data_notification();

    std::shared_ptr<QImage> get();

    void notified();
};

#endif // VIEWMODEL_H
