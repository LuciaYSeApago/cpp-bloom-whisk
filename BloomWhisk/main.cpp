#include "mainwindow.h"

#include <QApplication>

int main(int argc, char* argv[])
{
    //create app
    QApplication a(argc, argv);

    //create window
    MainWindow w;

    //show window
    w.show();

    //execute
    return QApplication::exec();
}
