#include "view.h"
#include <QApplication>
#include "common.h"
#include "app.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    App app;
    app.run();
    return a.exec();
}
