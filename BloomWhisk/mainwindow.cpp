#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "colors.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    //conects window with whatever is designed in ui
    ui->setupUi(this);

    setWindowTitle("BloomWhisk");

    //initial size (user can always change it)
    resize (900,600);

    setStyleSheet(
        "QMainWindow {"
            "background-color: " + BloomColors::Cream + ";"
        "}"
        "QWidget#centralwidget {"
            "background-color: " + BloomColors::Cream + ";"
        "}"
    );

}

MainWindow::~MainWindow() { delete ui; }
