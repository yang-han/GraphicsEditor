#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "common.h"
#include "model.h"
#include "view.h"
#include "viewmodel.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    Model::imgModel* p_img_model;
    ViewModel::imgViewModel* p_img_view_model;
    View::view* p_view;


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_button_open_clicked();

private:
    Ui::MainWindow *ui;
    cv::Mat img;
};

#endif // MAINWINDOW_H
