#ifndef CARD_H
#define CARD_H
#include <iostream>

enum suits
{
    CLUBS,//трефы
    DIAMONDS,//бубны
    HEARTS, //червы
    SPADES,
    UNKNOWN_S//пики
};
enum nominals
{
    ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
    JACK, QUEEN, KING, UNKNOWN_N};

class Card
{
public:

    Card(suits suit=UNKNOWN_S, nominals nominal=UNKNOWN_N):
    m_suit(suit),
    m_nominal(nominal),
    m_isUp(false){}

uint16_t getValue() const
{
    int val=0;

    if(m_nominal!=UNKNOWN_N && m_isUp)
    {
        val=m_nominal;
        if (val<=10)
            return val;
        else
            return 10;
    }
    return 0;
}
friend std::ostream& operator<<(std::ostream& os, const Card& aCard);
void Flip()   {m_isUp=!(m_isUp);}

protected:
    suits m_suit;
    nominals m_nominal;
    bool m_isUp;

};
std::ostream& operator<<(std::ostream& os, const Card& aCard)
{
    const std::string RANKS[] = {"0", "A", "2", "3", "4", "5", "6", "7", "8", "9",
                                 "10", "J", "Q", "K", "U" };
    const std::string SUITS[] = { "c","d","h","s","u"};
    if (aCard.m_isUp)
    {
        os << " ["<<RANKS[aCard.m_nominal] <<" "<< SUITS[aCard.m_suit]<<"] ";
    }
    else
    {
        os << " [XX] ";
    }
    return os;
};
#endif // CARD_H
