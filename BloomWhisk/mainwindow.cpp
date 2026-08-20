#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    //conects window with whatever is designed in ui
    ui->setupUi(this);

    setWindowTitle("BloomWhisk");

    //initial size (user can always change it)
    resize (900,600);

}

MainWindow::~MainWindow() { delete ui; }
