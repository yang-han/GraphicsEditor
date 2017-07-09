#ifndef MODEL_H
#define MODEL_H

#include "common.h"
#include "viewmodel.h"
class ViewModel;


class Model
{
private:
    std::shared_ptr<ViewModel> viewmodel;
    std::shared_ptr<cv::Mat> image;
public:
    Model();
    ~Model();
    void bind(std::shared_ptr<ViewModel> viewmodel);
    std::shared_ptr<cv::Mat> get();
    void load(std::string file_name);
    void notify();
};

#endif // MODEL_H
