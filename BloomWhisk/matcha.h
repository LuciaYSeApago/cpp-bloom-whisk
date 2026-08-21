#ifndef MATCHA_H
#define MATCHA_H

#include <QString>

class matcha
{
  private:

    QString NAME;
    QString INFO;
    int RATING;
    int TIMES_CONSUMED;

  public:
    matcha();

    matcha(
        const QString& NAME,
        const QString& INFO,
        int RATING,
        int TIMES_CONSUMED);

    void setName(const QString& NAME);
    QString getName() const;

    void setInfo (const QString& INFO);
    QString getInfo() const;

    void setRating(int RATING);
    int getRating() const;

    void setTimesConsumed(int TIMES_CONSUMED);
    int getTimesConsumed() const;

};

#endif // MATCHA_H
