#ifndef VIEWMODEL_H
#define VIEWMODEL_H
#include <QImage>
#include <memory>
#include "parameters.h"

class Model;
class Notification;

class ViewModel
{
private:
    QImage q_image;
    std::shared_ptr<Model> model;
    std::shared_ptr<Notification> notification;

public:
    ViewModel();
    void bind(std::shared_ptr<Model> model);
    void set_notification(std::shared_ptr<Notification> notification);
    void exec_open_file_command(Parameters params);

    QImage& get();
    void notified();
};

#endif // VIEWMODEL_H
