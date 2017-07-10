#include "model.h"
#include <opencv2/opencv.hpp>
#include "viewmodel.h"
#include <QDebug>

Model::Model()
{

}

void Model::open_file(std::string path){
    image = cv::imread(path);
//    qInfo() << QString("hehe");
    notify();
}

cv::Mat& Model::get(){
    return image;
}

void Model::bind(std::shared_ptr<ViewModel> viewmodel){
    this->viewmodel = viewmodel;
}

void Model::notify(){
    viewmodel->notified();
}
