#include "view.h"
#include "ui_view.h"
#include <QDir>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <QPixmap>
#include <QImage>
#include "Commands/open_file_command.h"
#include "Commands/alter_bright_command.h"
#include "Commands/filter_command.h"
#include "Commands/reset_command.h"
#include "Commands/save_file_command.h"
#include "Commands/save_bmp_command.h"
#include "Commands/rotate_command.h"
#include "Commands/crop_command.h"
#include "notification.h"
View::View(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::View)
{
    ui->setupUi(this);
    canvas = new MyView;
    canvas->resize(ui->graphicsView->size());
    update_view_notification = std::static_pointer_cast<Notification, UpdateViewNotification>(std::shared_ptr<UpdateViewNotification>(new UpdateViewNotification(std::shared_ptr<View>(this))));}

View::~View()
{
    delete ui;
}

//void View::update(const QImage &q_image){
//    qInfo() << QString("update");
//    ui->label->setPixmap(QPixmap::fromImage(q_image));
//}

void View::set_img(std::shared_ptr<QImage> image){
    this->q_image = image;
}
void View::update(){
	QGraphicsScene* t = new QGraphicsScene;
	QPixmap pic = QPixmap::fromImage(*q_image);
	t->addPixmap(pic.scaled(ui->graphicsView->size(),Qt::KeepAspectRatio));
	ui->graphicsView->setScene(t);
	ui->graphicsView->show();
}

void View::set_open_file_command(std::shared_ptr<Command> command){
    open_file_command = command;
}
void View::set_alter_bright_command(std::shared_ptr<Command> command){
    alter_bright_command = command;
}
void View::set_filter_rem_command(std::shared_ptr<Command> command){
    filter_rem_command = command;
}
void View::set_reset_command(std::shared_ptr<Command> command){
    reset_command = command;
}
void View::set_detect_face_command(std::shared_ptr<Command> command){
    detect_face_command = command;
}
void View::set_save_file_command(std::shared_ptr<Command> command){
    save_file_command = command;
}
void View::set_save_bmp_file_command(std::shared_ptr<Command> command){
    save_bmp_file_command = command;
}
void View::set_rotate_command(std::shared_ptr < Command > command) {
    rotate_command = command;
}
void View::set_crop_command(std::shared_ptr<Command> command) {
    crop_command = command;
}

std::shared_ptr<Notification> View::get_update_view_notification(){
    return update_view_notification;
}


void View::on_button_open_clicked()
{

    auto path = QDir::homePath();
    auto file_name = QFileDialog::getOpenFileName(this, tr("打开文件"), path,
                                                        tr("image(*.png *.jpg *.bmp *.tiff);;AllFile(*)"));
    if(file_name.isEmpty()){
        QMessageBox::information(this, tr("Failed to Open this!"), tr("OK"));
        return;
    }
    qInfo() << file_name;
    open_file_command->set_parameters(std::static_pointer_cast<Parameters, PathParameters>(std::shared_ptr<PathParameters>(new PathParameters(file_name.toStdString()))));
//    qInfo() << file_name;
    open_file_command->exec();
//    qInfo() << file_name;
}

void View::on_brightSlider_valueChanged(int value)
{
    int contrast = ui->contrastSlider->value();
    alter_bright_command->set_parameters(std::static_pointer_cast<Parameters, brightAndContrastParameters>(std::shared_ptr<brightAndContrastParameters>(new brightAndContrastParameters(value,contrast))));
    alter_bright_command->exec();
}

void View::on_contrastSlider_valueChanged(int value)
{
    int bright = ui->brightSlider->value();
    alter_bright_command->set_parameters(std::static_pointer_cast<Parameters, brightAndContrastParameters>(std::shared_ptr<brightAndContrastParameters>(new brightAndContrastParameters(bright,value))));
    alter_bright_command->exec();
}

void View::on_filter_1_clicked()
{
    filter_rem_command->exec();
}


void View::on_reset_clicked()
{
    reset_command->exec();
}

void View::on_actionOpen_File_triggered()
{
    on_button_open_clicked();
}

void View::on_button_detect_face_clicked()
{
    detect_face_command->exec();
}

void View::on_actionSave_triggered()
{
    auto path = QDir::homePath();
    auto file_name = QFileDialog::getSaveFileName(this, tr("保存文件"), path,
                                                        tr("image(*.png *.jpg *.bmp *.tiff);;AllFile(*)"));
    if(file_name.isEmpty()){
        QMessageBox::information(this, tr("Failed to Open this!"), tr("Failed to Open this!"));
        return;
    }
    qInfo() << file_name;
    save_file_command->set_parameters(std::static_pointer_cast<Parameters, PathParameters>(std::shared_ptr<PathParameters>(new PathParameters(file_name.toStdString()))));
    save_file_command->exec();
}

void View::on_action_bmp_triggered()
{
    auto path = QDir::homePath();
    auto file_name = QFileDialog::getSaveFileName(this, tr("保存为bmp文件"), path,
                                                        tr("image(*.png *.jpg *.bmp *.tiff);;AllFile(*)"));
    if(file_name.isEmpty()){
        QMessageBox::information(this, tr("Failed to Open this!"), tr("Failed to Open this!"));
        return;
    }
    qInfo() << file_name;
    save_bmp_file_command->set_parameters(std::static_pointer_cast<Parameters, PathParameters>(std::shared_ptr<PathParameters>(new PathParameters(file_name.toStdString()))));
    save_bmp_file_command->exec();
}

void View::on_action_png_triggered()
{
    on_action_bmp_triggered();
}

void View::on_action_jpeg_triggered()
{
    on_action_bmp_triggered();
}

void View::on_rotateSlider_valueChanged(int value)
{
    rotate_command->set_parameters(std::static_pointer_cast<Parameters, IntParameters>(std::shared_ptr<IntParameters>(new IntParameters(value))));
    rotate_command->exec();
}
