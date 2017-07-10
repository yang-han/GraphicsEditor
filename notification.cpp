#include "notification.h"
#include "view.h"
#include "viewmodel.h"

Notification::Notification()
{

}


void Notification::bind(std::shared_ptr<ViewModel> viewmodel, std::shared_ptr<View> view){
    this->viewmodel = viewmodel;
    this->view = view;
}


void Notification::exec(){
    view->update(viewmodel->get());
}
