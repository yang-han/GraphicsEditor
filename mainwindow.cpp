#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QFileDialog>
#include <QDebug>
#include <QPixmap>
#include <QMessageBox>
#include "view.h"


#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), p_view(new View::view()), p_img_model(new Model::imgModel()),
    p_img_view_model(new ViewModel::imgViewModel())
{
    ui->setupUi(this);

    p_img_view_model->set(p_img_model, p_view);
    p_view->set(p_img_view_model, ui);

}

MainWindow::~MainWindow()
{
    delete p_img_model;
    delete p_img_view_model;
    delete p_view;
    delete ui;
}

void MainWindow::on_button_open_clicked()
{
    auto path = QDir::homePath();
    auto file_name = QFileDialog::getOpenFileName(this, tr("打开文件"), path,
                                                        tr("image(*.png *.jpg *.bmp *.tiff);;AllFile(*)"));
    if(file_name.isEmpty()){
        QMessageBox::information(this, tr("Failed to Open this!"), tr("OK"));
        return;
    }
    qInfo() << file_name;
    p_img_model->load(file_name.toStdString());
//    img_view_model.get() = Mat2QImage(img_model.get());
//    ui->label->setPixmap(QPixmap::fromImage(img_view_model.get()));
    notify(p_img_view_model);

}
