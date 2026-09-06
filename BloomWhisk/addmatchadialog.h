#ifndef ADDMATCHADIALOG_H
#define ADDMATCHADIALOG_H

#include "matcha.h"
#include <QDialog>

namespace Ui
{
class AddMatchaDialog;
}

class AddMatchaDialog : public QDialog
{
    Q_OBJECT

  public:
    explicit AddMatchaDialog(QWidget* parent = nullptr);
    ~AddMatchaDialog();

    matcha createMatcha() const;

  private:
    Ui::AddMatchaDialog* ui;
};

#endif // ADDMATCHADIALOG_H
