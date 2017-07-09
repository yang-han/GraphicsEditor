#ifndef VIEWMODEL_H
#define VIEWMODEL_H
#include "common.h"
#include "model.h"

class ViewModel
{
private:
    std::shared_ptr<QImage> q_image;
    std::shared_ptr<Model> model;

public:
    ViewModel();
    void bind(std::shared_ptr<Model> model);
    void exec_open_file_command();
};

#endif // VIEWMODEL_H
