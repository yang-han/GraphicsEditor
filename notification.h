#ifndef NOTIFICATION_H
#define NOTIFICATION_H
#include "common.h"
#include "view.h"
#include "viewmodel.h"

class View;
class ViewModel;


class Notification
{
protected:
    std::shared_ptr<View> view;
    std::shared_ptr<ViewModel> viewmodel;

public:
    Notification();
    void bind(std::shared_ptr<View> view, std::shared_ptr<ViewModel> viewmodel);
    virtual void exec();
};

#endif // NOTIFICATION_H
