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


    std::shared_ptr<Command> open_file_command;
    std::shared_ptr<Command> alter_bright_command;
    std::shared_ptr<Command> filter_rem_command;
    std::shared_ptr<Command> reset_command;
    std::shared_ptr<Command> detect_face_command;
    std::shared_ptr<Command> save_file_command;

    std::shared_ptr<Notification> update_display_data_notification;

    std::shared_ptr<Notification> update_view_notification;

public:
    ViewModel();
    void bind(std::shared_ptr<Model> model);
    void exec_open_file_command(std::string path);
    void exec_alter_bright_command(int nBright, int nContrast);
    void exec_filter_rem_command();
    void exec_reset_command();
    void exec_detect_face_command();
    void exec_save_file_command(std::string path);

    void set_update_view_notification(std::shared_ptr<Notification> notification);

    std::shared_ptr<Command> get_open_file_command();
    std::shared_ptr<Command> get_alter_bright_command();
    std::shared_ptr<Command> get_filter_rem_command();
    std::shared_ptr<Command> get_reset_command();
    std::shared_ptr<Command> get_detect_face_command();
    std::shared_ptr<Command> get_save_file_command();

    std::shared_ptr<Notification> get_update_display_data_notification();
    std::shared_ptr<QImage> get();

    void notified();
};

#endif // VIEWMODEL_H
