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

//    std::cout << path << std::endl;
    image = cv::imread(path);
    if(image.empty()){
        qInfo() << "false";
    }else{
        notify();
    }
}

cv::Mat& Model::get(){
    return image;
}

//void Model::bind(std::shared_ptr<ViewModel> viewmodel){
//    this->viewmodel = viewmodel;
//}

void Model::set_update_display_data_notification(std::shared_ptr<Notification> notification){
    this->update_display_data_notification = notification;
}

void Model::notify(){
    update_display_data_notification->exec();
}
