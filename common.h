#ifndef COMMON_H
#define COMMON_H
#include <opencv2/opencv.hpp>
#include <QImage>


QImage Mat2QImage(cv::Mat const& src);

cv::Mat QImage2Mat(QImage const& src);

#endif // COMMON_H
