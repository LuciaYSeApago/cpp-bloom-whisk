#include "matchacard.h"
#include "ui_matchacard.h"

MatchaCard::MatchaCard(QWidget* parent) : QWidget(parent), ui(new Ui::MatchaCard)
{
    ui->setupUi(this);
}

MatchaCard::~MatchaCard() { delete ui; }
