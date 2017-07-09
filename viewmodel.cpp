#include "viewmodel.h"

ViewModel::ViewModel():q_image(new QImage)
{

}

ViewModel::~ViewModel(){
    delete q_image;
}

void ViewModel::bind(std::shared_ptr<Model> model){
    this->model = model;
}
