#ifndef MATCHACARD_H
#define MATCHACARD_H

#include <QWidget>
#include "matcha.h"

namespace Ui
{
class MatchaCard;
}

class MatchaCard : public QWidget
{
    Q_OBJECT

  public:
    explicit MatchaCard(QWidget* parent = nullptr);
    ~MatchaCard();

    void setMatcha(const matcha& m);

  private:
    Ui::MatchaCard* ui;
};

#endif // MATCHACARD_H
