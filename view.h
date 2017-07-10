#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>
#include <memory>
#include <QImage>
class OpenFileCommand;

namespace Ui {
class View;
}

class View : public QMainWindow
{
    Q_OBJECT

public:
    explicit View(QWidget *parent = 0);
    ~View();
    void update(QImage& q_image);
    void set_open_file_command(std::shared_ptr<OpenFileCommand>);

private slots:
    void on_button_open_clicked();

private:
    Ui::View *ui;
    std::shared_ptr<OpenFileCommand> open_file_command;
};

#endif // VIEW_H
