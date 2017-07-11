#include "notification.h"
#include "view.h"
#include "viewmodel.h"
#include <QDebug>

Notification::Notification()
{

}


//void Notification::bind(std::shared_ptr<ViewModel>& viewmodel, std::shared_ptr<View>& view){
//    this->viewmodel = viewmodel;
//    this->view = view;
//    std::cout << "bind view "<< this->view.get() << std::endl;
//}


//void Notification::exec(){
//    std::cout << "crash!" << std::endl;
//    std::cout << "view "<< this->view.get() << std::endl;
//    qInfo() << QString("notif exec");
////    view->update(viewmodel->get());
//    view->test();
//    view->update();
//    qInfo() << QString("?????");
//}
