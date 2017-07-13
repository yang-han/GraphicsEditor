#include "viewmodel.h"
#include <QImage>
#include "parameters.h"
#include "model.h"
#include "common.h"
#include "notification.h"
#include "command.h"
#include "Commands/open_file_command.h"
#include "Commands/alter_bright_command.h"
#include "Commands/filter_command.h"
#include "Commands/reset_command.h"
#include "Commands/detect_face_command.h"
#include "Commands/save_file_command.h"
#include "Commands/save_bmp_command.h"
#include <QDebug>
ViewModel::ViewModel():q_image(new QImage){
    open_file_command = std::static_pointer_cast<Command, OpenFileCommand>(std::shared_ptr<OpenFileCommand> (new OpenFileCommand(std::shared_ptr<ViewModel>(this))));
    alter_bright_command = std::static_pointer_cast<Command, AlterBrightCommand>(std::shared_ptr<AlterBrightCommand>(new AlterBrightCommand(std::shared_ptr<ViewModel>(this))));
    update_display_data_notification = std::static_pointer_cast<Notification, UpdateDisplayDataNotification>
            (std::shared_ptr<UpdateDisplayDataNotification>(new UpdateDisplayDataNotification(std::shared_ptr<ViewModel>(this))));
    filter_rem_command = std::static_pointer_cast<Command, FilterRemCommand>(std::shared_ptr<FilterRemCommand>(new FilterRemCommand(std::shared_ptr<ViewModel>(this))));
    reset_command = std::static_pointer_cast<Command, ResetCommand>(std::shared_ptr<ResetCommand>(new ResetCommand(std::shared_ptr<ViewModel>(this))));
    detect_face_command = std::static_pointer_cast<Command, DetectFaceCommand>(std::shared_ptr<DetectFaceCommand>(new DetectFaceCommand(std::shared_ptr<ViewModel>(this))));
    save_file_command = std::static_pointer_cast<Command, SaveFileCommand>(std::shared_ptr<SaveFileCommand>(new SaveFileCommand(std::shared_ptr<ViewModel>(this))));
    save_bmp_file_command = std::static_pointer_cast<Command, SaveBmpCommand>(std::shared_ptr<SaveBmpCommand>(new SaveBmpCommand(std::shared_ptr<ViewModel>(this))));

//    std::cout << q_image.get() << std::endl;
}

std::shared_ptr<Command> ViewModel::get_detect_face_command(){
    return detect_face_command;
}

std::shared_ptr<Command> ViewModel::get_save_file_command(){
    return save_file_command;
}

void ViewModel::exec_detect_face_command(){
    model->detect_face();
}

void ViewModel::exec_open_file_command(std::string path){
//    qInfo() << QString("xixi");
    model->open_file(path);
//    qInfo() << QString("xixi");
}
void ViewModel::exec_alter_bright_command(int nBright, int nContrast){
    //some operations to transfer "nBright" to "'int' nBright"
    model->alterBrightAndContrast(nBright, nContrast);

}
void ViewModel::exec_filter_rem_command(){
    model->filterReminiscence();
}

void ViewModel::exec_reset_command(){
    model->reset();
}

void ViewModel::exec_save_file_command(std::string path){
     model->save_file(path);
}
void ViewModel::exec_save_bmp_file_command(std::string path){
     model->save_bmp_file(path);
}
void ViewModel::bind(std::shared_ptr<Model> model){
    this->model = model;
}

std::shared_ptr<Command> ViewModel::get_open_file_command(){
    return open_file_command;
}

std::shared_ptr<Command> ViewModel::get_alter_bright_command(){
    return alter_bright_command;
}

std::shared_ptr<Command> ViewModel::get_filter_rem_command(){
    return filter_rem_command;
}

std::shared_ptr<Command> ViewModel::get_reset_command(){
    return reset_command;
}

std::shared_ptr<Command> ViewModel::get_save_bmp_file_command(){
    return save_bmp_file_command;
}

std::shared_ptr<Notification> ViewModel::get_update_display_data_notification(){
    return update_display_data_notification;
}



std::shared_ptr<QImage> ViewModel::get(){
    return q_image;
}

void ViewModel::set_update_view_notification(std::shared_ptr<Notification> notification)
{
    update_view_notification = notification;
}

void ViewModel::notified(){
    *q_image = Mat2QImage(model->get());
    update_view_notification->exec();
}
