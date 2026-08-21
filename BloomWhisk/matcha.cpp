#include "matcha.h"

using namespace std;

matcha::matcha()
{
    NAME = "";
    INFO = "";
    RATING = 0;
    TIMES_CONSUMED = 0;
}

matcha::matcha(const QString& NAME, const QString& INFO, int RATING, int TIMES_CONSUMED)
    : NAME(NAME),
      INFO(INFO),
      RATING(RATING),
      TIMES_CONSUMED(TIMES_CONSUMED)
{}

void matcha::setName(const QString& NAME)
{
    this -> NAME = NAME;
}
QString matcha::getName() const
{
    return NAME;
}

void matcha::setInfo(const QString& INFO)
{
    this -> INFO = INFO;
}
QString matcha::getInfo() const
{
    return INFO;
}

void matcha::setRating(int RATING)
{
    this -> RATING = RATING;
}
int matcha::getRating() const
{
    return RATING;
}

void matcha::setTimesConsumed(int TIMES_CONSUMED)
{
    this -> TIMES_CONSUMED = TIMES_CONSUMED;
}
int matcha::getTimesConsumed() const
{
    return TIMES_CONSUMED;
}
