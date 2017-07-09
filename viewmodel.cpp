#include "viewmodel.h"
#include "model.h"
#include "common.h"

ViewModel::ViewModel():q_image(new QImage)
{

}

ViewModel::~ViewModel(){
//    delete q_image;
}

void ViewModel::bind(std::shared_ptr<Model> model, std::shared_ptr<Notification> notification){
    this->model = model;
    this->notification = notification;
}

void ViewModel::exec_open_file_command(Parameters params){
    model->load(params.get_path());
}

void ViewModel::notified(){
    q_image = std::make_shared<QImage>(Mat2QImage(*(model->get())));
    notification->exec();

}

std::shared_ptr<QImage> ViewModel::get_img(){
    return q_image;
}
