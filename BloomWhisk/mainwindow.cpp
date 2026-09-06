#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "colors.h"
#include "matcha.h"
#include "addmatchadialog.h"

#include <QPushButton>
#include <QDebug>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    //conects window with whatever is designed in ui
    ui->setupUi(this);

    //add matchas to list
    matchas.append(
        matcha(
            "Ippodo Sayaka",
            "Smooth, creamy",
            5,
            12
        )
    );

    matchas.append(
        matcha(
            "Yunomi Hojicha",
            "Roasted, warm and nutty",
            4,
            7
        )
    );

    displayMatchas();

    //connect with addMatchaWindow
    connect (ui -> addMatchaButton, &QPushButton::clicked, this &MainWindow::addMatcha);
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
void MainWindow::displayMatcha(const matcha&m , int cardNumber)
{
    QString stars = QString(m.getRating(), u'★');

    if (cardNumber == 1)
    {
        ui -> matchaLabel1 -> setText(m.getName());
        ui -> infoLabel1 -> setText(m.getInfo());
        ui -> ratingLabel1 -> setText(stars);
        ui -> consumedLabel1 -> setText("Consumed: "+ QString::number(m.getTimesConsumed()) + " times");
    }
    else if (cardNumber == 2)
    {
        ui -> matchaLabel2 -> setText(m.getName());
        ui -> infoLabel2 -> setText(m.getInfo());
        ui -> ratingLabel2 -> setText(stars);
        ui -> consumedLabel2 -> setText("Consumed: "+ QString::number(m.getTimesConsumed()) + " times");
    }
}

void MainWindow :: displayMatchas()
{
    if (matchas.size() > 0)
    {
        displayMatcha(matchas[0],1);
    }
    else if (matchas.size() > 1)
    {
        displayMatcha(matchas[1],2);
    }
}

void MainWindow::addMatcha()
{
    AddMatchaDialog dialog(this);

    if (dialog.exec() == QDialog::Accepted)
    {
        matchas.append(dialog.createMatcha());

        displayMatchas();

        statusBar()->showMessage(
            "Matcha added! Total: " + QString::number(matchas.size())
            );
    }
}

MainWindow::~MainWindow() { delete ui; }
