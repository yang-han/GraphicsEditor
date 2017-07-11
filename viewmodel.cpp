#include "viewmodel.h"
#include <QImage>
#include "parameters.h"
#include "model.h"
#include "common.h"
#include "notification.h"
#include "command.h"
#include "Commands/open_file_command.h"
#include <QDebug>
ViewModel::ViewModel():q_image(new QImage){
    open_file_command = std::static_pointer_cast<Command, OpenFileCommand>(std::shared_ptr<OpenFileCommand> (new OpenFileCommand(std::shared_ptr<ViewModel>(this))));

    std::cout << q_image.get() << std::endl;
}


void ViewModel::exec_open_file_command(Parameters params){
//    qInfo() << QString("xixi");
    model->open_file(params.get_path());
//    qInfo() << QString("xixi");
}

void ViewModel::bind(std::shared_ptr<Model> model){
    this->model = model;
}

std::shared_ptr<Command> ViewModel::get_open_file_command(){
    return open_file_command;
}


std::shared_ptr<QImage> ViewModel::get(){
    return q_image;
}

void ViewModel::set_notification(std::shared_ptr<ViewModelNotification> notification){
    this->viewmodel_notification = notification;
}

void ViewModel::notified(){
    *q_image = Mat2QImage(model->get());
//    std::cout << "q_image __ vm notified"<<q_image.get() << std::endl;
//    qInfo() << QString("notified");
    viewmodel_notification->exec();
}
