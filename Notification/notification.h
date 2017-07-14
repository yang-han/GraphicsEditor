#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <memory>
#include "View/view.h"
#include "ViewModel/viewmodel.h"
class ViewModel;
class View;

class Notification
{
private:
//    std::shared_ptr<ViewModel> viewmodel;
//    std::shared_ptr<View> view;

public:
    Notification();
//    void bind(std::shared_ptr<ViewModel>& viewmodel, std::shared_ptr<View>& view);
    virtual void exec() = 0;
};



class UpdateDisplayDataNotification: public Notification{
private:
    std::shared_ptr<ViewModel> viewmodel;
public:
    UpdateDisplayDataNotification(std::shared_ptr<ViewModel> vm):viewmodel(vm){}
    void exec(){
        viewmodel->notified();
    }
};


class UpdateViewNotification: public Notification{
private:
    std::shared_ptr<View> view;
public:
    UpdateViewNotification(std::shared_ptr<View> v):view(v){}
    void exec(){
        view->update();
    }
};


#endif // NOTIFICATION_H
