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
     cv::Mat image; //for showing
     cv::Mat originImg; //for store the original
     cv::Mat interImg; //intermediate variable
     std::shared_ptr<Notification> update_display_data_notification;
public:
    Model(){}
    void set_update_display_data_notification(std::shared_ptr<Notification> notification);
    void open_file(std::string path);
    cv::Mat& get();
    cv::Mat& getOrigin();
    void notify();
    void save_file(std::string path);
    void save_bmp_file(std::string path);

    void alterBrightAndContrast(int nbright, int nContrast);
    /* When nbright = -200, the picture is almost full of black.
     * When nbright = 0, it shows the original picture.
     * When nbright = 200, the picture is almost full of white.
     * So we prefer to having 'nbright' between -150 to 150
     */

    /* When nContrast = 100, it shows the original picture.
     * When nContrast = 0, the picture is full of black.
     * When nContrast = 300, the picture has high contrast.
     * So here, nContrast should be from 0 to 300.
     */

    void detect_face();


    void filterReminiscence(); //Filter No.1
    void AeroGlassscence();          //Filter No.2
	void reset();
    void rotate(double angle);
    /* angle should be 'degree', such as 90 degree.
     * When angle is equal to 90 degree, the picture will turn right.
     */
    void crop(int x1, int y1, int x2, int y2);
};

#endif // MODEL_H
