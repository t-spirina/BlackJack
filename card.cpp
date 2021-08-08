#include "card.h"


Card::Card(rank rank, suit suit, bool IsFaceUp) : m_Rank(rank), m_Suit(suit), m_IsFaceUp(IsFaceUp)
{
}

void Card::Flip()
{
    m_IsFaceUp = !(m_IsFaceUp);
}

// Method GetValue returns the Card value
int Card::GetValue() const
{
    // if card is tirned face down, return 0
    int value = 0;
    if (m_IsFaceUp)
    {
        // value is the Card value
        value = m_Rank;
    }

    return value;
}

// Overload the << operator for sending Card object to cout
std::ostream& operator<< (std::ostream& os, const Card& aCard)
{
    const std::string RANKS[] = { "0", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
    const std::string SUITS[] = { "c", "d", "h", "s" };

    if (aCard.m_IsFaceUp)
    {
        os << RANKS[aCard.m_Rank] << SUITS[aCard.m_Suit];
    }
    else
    {
        os << "XX";
    }

    return os;
}
