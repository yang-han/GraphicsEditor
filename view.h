#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>
#include "command.h"
#include "common.h"
#include "Commands/open_file_command.h"

namespace Ui {
class view;
}
class OpenFileCommand;

class View : public QMainWindow
{
    Q_OBJECT

public:
    explicit View(QWidget *parent = 0);
    ~View();
    void update(std::shared_ptr<QImage> q_img);
    void setOpenFileCommand(std::shared_ptr<OpenFileCommand> command);
private slots:
    void on_button_open_clicked();

private:
    Ui::view *ui;
    std::shared_ptr<OpenFileCommand> open_file_command;
};

#endif // VIEW_H
