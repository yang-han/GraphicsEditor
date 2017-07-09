#include "view.h"
#include "ui_view.h"
#include "common.h"
#include "Commands/open_file_command.h"

View::View(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::view)
{
    ui->setupUi(this);
}

View::~View()
{
    delete ui;
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
    open_file_command->get_params().set_path(file_name.toStdString());
    open_file_command->exec();

}


void View::setOpenFileCommand(std::shared_ptr<OpenFileCommand> command){
    open_file_command = command;
}

void View::update(std::shared_ptr<QImage> q_img){
    ui->label->setPixmap(QPixmap::fromImage(*q_img));
}
