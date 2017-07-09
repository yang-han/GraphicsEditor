#include "model.h"
#include "common.h"
#include "viewmodel.h"

Model::Model():image(new cv::Mat){

}

Model::~Model(){

}


void Model::bind(std::shared_ptr<ViewModel> viewmodel){
    this->viewmodel = viewmodel;
}

std::shared_ptr<cv::Mat> Model::get(){
    return image;
}


void Model::load(std::string file_name){
    (*image.get()) = cv::imread(file_name);
}

void Model::notify(){
    viewmodel->notified();
}





