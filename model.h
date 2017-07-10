#ifndef MODEL_H
#define MODEL_H

#include <opencv2/opencv.hpp>
#include <memory>
#include <string>
class ViewModel;

class Model
{
private:
     cv::Mat image;
     std::shared_ptr<ViewModel> viewmodel;
public:
    Model();
    void bind(std::shared_ptr<ViewModel> viewmodel);
    void open_file(std::string path);
    cv::Mat& get();
    void notify();
};

#endif // MODEL_H
