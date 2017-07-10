#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <memory>
class ViewModel;
class View;

class Notification
{
private:
    std::shared_ptr<ViewModel> viewmodel;
    std::shared_ptr<View> view;

public:
    Notification();
    void bind(std::shared_ptr<ViewModel> viewmodel, std::shared_ptr<View> view);
    void exec();
};

#endif // NOTIFICATION_H
