#include "model.h"
#include "common.h"


Model::Model():image(new cv::Mat){

}

Model::~Model(){

}

std::shared_ptr<cv::Mat> Model::get(){
    return image;
}


void load(std::string file_name){
    (*image.get()) = cv::imread(file_name);
}





