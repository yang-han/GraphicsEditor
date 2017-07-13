#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>
#include <memory>
#include <QImage>
#include <QDebug>
#include <iostream>
#include "command.h"


class Notification;

namespace Ui {
class View;
}

class View : public QMainWindow
{
    Q_OBJECT

public:
    explicit View(QWidget *parent = 0);
    ~View();

    void update();
    void set_img(std::shared_ptr<QImage> image);
    void set_open_file_command(std::shared_ptr<Command>);
    void set_alter_bright_command(std::shared_ptr<Command>);
    void set_filter_rem_command(std::shared_ptr<Command>);
    void set_reset_command(std::shared_ptr<Command>);
    std::shared_ptr<Notification> get_update_view_notification();

private slots:
    void on_button_open_clicked();

    void on_brightSlider_valueChanged(int value);

    void on_contrastSlider_valueChanged(int value);

    void on_filter_1_clicked();

    void on_reset_clicked();

	void on_actionOpen_File_triggered();

private:
    Ui::View *ui;
    std::shared_ptr<QImage> q_image;
    std::shared_ptr<Command> open_file_command;
    std::shared_ptr<Command> alter_bright_command;
    std::shared_ptr<Command> filter_rem_command;
    std::shared_ptr<Command> reset_command;

    std::shared_ptr<Notification> update_view_notification;
};

#endif // VIEW_H
