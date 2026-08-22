#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "colors.h"
#include "matcha.h"

#include <QDebug>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    //conects window with whatever is designed in ui
    ui->setupUi(this);

    matcha sayaka(
        "Ippodo Sayaka",
        "Smooth, creamy",
        5,
        12
        );

    qDebug()<< sayaka.getName();
    qDebug()<< sayaka.getInfo();
    qDebug()<< sayaka.getRating();
    qDebug()<< sayaka.getTimesConsumed();

    setWindowTitle("BloomWhisk");

    //initial size (user can always change it)
    //resize (900,600);

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
