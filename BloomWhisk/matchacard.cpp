#include "matchacard.h"
#include "ui_matchacard.h"

#include <QPushButton>

MatchaCard::MatchaCard(QWidget* parent) : QWidget(parent), ui(new Ui::MatchaCard)
{
    ui->setupUi(this);

    //button funcionality, detects click
    connect(ui->consumeButton, &QPushButton::clicked,this, [this]()
        {
            emit consumeRequested();
        }
    );
}

MatchaCard::~MatchaCard() { delete ui; }

void MatchaCard::setMatcha(const matcha& m)
{
    ui -> nameLabel -> setText(m.getName());
    ui -> infoLabel -> setText(m.getInfo());

    //for the stars
    QString stars = QString(m.getRating(), u'★');
    ui -> ratingLabel -> setText(stars);

    ui -> consumedLabel -> setText ("Consumed: " + QString::number(m.getTimesConsumed()) + " times");
}