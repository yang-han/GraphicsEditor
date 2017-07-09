#ifndef VIEWMODEL_H
#define VIEWMODEL_H
#include "common.h"
#include "model.h"
#include "parameters.h"
#include "notification.h"
class Model;
class Notification;

class ViewModel
{
private:
    std::shared_ptr<QImage> q_image;
    std::shared_ptr<Model> model;
    std::shared_ptr<Notification> notification;

public:
    ViewModel();
    ~ViewModel();
    void bind(std::shared_ptr<Model> model, std::shared_ptr<Notification> notification);
    void exec_open_file_command(Parameters params);
    void notified();
    std::shared_ptr<QImage> get_img();
};

#endif // VIEWMODEL_H
