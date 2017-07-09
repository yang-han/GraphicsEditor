#include "notification.h"
#include "viewmodel.h"
#include "view.h"

Notification::Notification()
{

}

void Notification::bind(std::shared_ptr<View> _view, std::shared_ptr<ViewModel> _viewmodel)
{
    view = _view;
    viewmodel = _viewmodel;
}


void Notification::exec(){
    view->update(viewmodel->get_img());
}
