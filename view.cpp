#include "view.h"
#include "ui_view.h"
#include <QDir>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <QPixmap>
#include "Commands/open_file_command.h"

View::View(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::View)
{
    ui->setupUi(this);
}

View::~View()
{
    delete ui;
}

void View::update(QImage &q_image){
    ui->label->setPixmap(QPixmap::fromImage(q_image));
}

void View::set_open_file_command(std::shared_ptr<OpenFileCommand> command){
    open_file_command = command;
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
    open_file_command->get_params_handle().set_path(file_name.toStdString());
    open_file_command->exec();
}
