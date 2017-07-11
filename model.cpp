#include "model.h"
#include <opencv2/opencv.hpp>
#include "viewmodel.h"
#include "notification.h"
#include <QDebug>
#include <iostream>
Model::Model()
{

}

void Model::open_file(std::string path){

    std::cout << path << std::endl;
    image = cv::imread(path);

    std::cout << path << std::endl;
//    qInfo() << QString("hehe");
    notify();
}

cv::Mat& Model::get(){
    return image;
}

//void Model::bind(std::shared_ptr<ViewModel> viewmodel){
//    this->viewmodel = viewmodel;
//}

void Model::set_notification(std::shared_ptr<ModelNotification> model_notification){
    this->model_notification = model_notification;
}

void Model::notify(){
    model_notification->exec();
}
