#include "addmatchadialog.h"
#include "ui_addmatchadialog.h"
#include <QDialogButtonBox>

AddMatchaDialog::AddMatchaDialog(QWidget* parent) : QDialog(parent), ui(new Ui::AddMatchaDialog)
{
    ui->setupUi(this);

    connect(ui -> buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(ui -> buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
}

matcha AddMatchaDialog::createMatcha() const
{
    return matcha(
        ui -> nameLineEdit -> text(),
        ui -> infoLineEdit -> text(),
        ui -> ratingSpingBox -> value(),
        ui -> consumedSpingBox-> value()
        );
}
AddMatchaDialog::~AddMatchaDialog() { delete ui; }
