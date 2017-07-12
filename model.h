#ifndef MODEL_H
#define MODEL_H

#include <opencv2/opencv.hpp>
#include <memory>
#include <string>
class ViewModel;
class Notification;

class Model
{
private:
     cv::Mat image;
     std::shared_ptr<Notification> update_display_data_notification;
public:
    Model();
    void set_update_display_data_notification(std::shared_ptr<Notification> notification);
    void open_file(std::string path);
    cv::Mat& get();
    void notify();
};

#endif // MODEL_H
