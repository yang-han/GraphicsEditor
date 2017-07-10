#include "viewmodel.h"
#include <QImage>
#include "parameters.h"
#include "model.h"
#include "common.h"
#include "notification.h"
#include <QDebug>
ViewModel::ViewModel(){

}


void ViewModel::exec_open_file_command(Parameters params){
    model->open_file(params.get_path());
}

void ViewModel::bind(std::shared_ptr<Model> model){
    this->model = model;
}

QImage& ViewModel::get(){
    return q_image;
}

void ViewModel::set_notification(std::shared_ptr<Notification> notification){
    this->notification = notification;
}

void ViewModel::notified(){
    q_image = Mat2QImage(model->get());
//    qInfo() << QString("JKL");
    notification->exec();


}
