#ifndef MODEL_H
#define MODEL_H

#include <opencv2/opencv.hpp>
#include <memory>
#include <string>
class ViewModel;
class ModelNotification;

class Model
{
private:
     cv::Mat image;
     std::shared_ptr<ModelNotification> model_notification;
public:
    Model();
    void set_notification(std::shared_ptr<ModelNotification> model_notification);
    void open_file(std::string path);
    cv::Mat& get();
    void notify();
};

#endif // MODEL_H
