#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "colors.h"
#include "matcha.h"
#include "matchacard.h"

#include <QPushButton>
#include <QDebug>
#include <QVBoxLayout>
#include <QFrame>
#include <QLabel>
#include <QLayout>
#include <QLayoutItem>
#include <QSpacerItem>
#include <QSizePolicy>

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
    connect(ui->addMatchaButton, &QPushButton::clicked, this, &MainWindow::addMatcha);
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

void MainWindow::displayMatchas()
{
    //show first the container
    QLayout *layout = ui->cardsContainer->layout();

    //remove cards currently shown.
    while (QLayoutItem *item = layout -> takeAt(0))
    {
        delete item -> widget();
        delete item;
    }

    //create one matchaCard for each matcha in collection
    for (int index = 0; index < matchas.size(); index++)
    {
        const matcha& m = matchas[index];

        MatchaCard *card = new MatchaCard(ui -> cardsContainer);
        card -> setMatcha(m);

        //connect each matcha card with "array position".
        connect (card, &MatchaCard::consumeRequested, this, [this, index]()
        {
            //adds one to times consumed
            matchas[index].addTimesConsumed();
            displayMatchas();
        }
        );

        layout -> addWidget(card);
    }
    //keep cards aligned at the top

    layout -> addItem(new QSpacerItem(0,0, QSizePolicy::Minimum, QSizePolicy::Expanding));
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
