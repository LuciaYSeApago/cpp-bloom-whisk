#ifndef MATCHACARD_H
#define MATCHACARD_H

#include <QWidget>

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

  private:
    Ui::MatchaCard* ui;
};

#endif // MATCHACARD_H
