#ifndef COMMON_H
#define COMMON_H

#include <opencv2/opencv.hpp>
#include <QImage>
#include <QPixmap>
#include <QDir>
#include <QDialog>
#include <QDebug>
#include <QString>
#include <QMessageBox>
#include <memory>

enum Type {
    OK, OPEN_FILE,
};

QImage Mat2QImage(cv::Mat const& src);

cv::Mat QImage2Mat(QImage const& src);

#endif // COMMON_H
