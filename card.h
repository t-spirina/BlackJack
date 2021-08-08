#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <string>
// класс описывает карту
class Card {
    public:
        enum rank {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK=10, QUEEN=10, KING=10};
        enum suit {CLUBS, DIAMONDS, HEARTS, SPADES};

        Card(rank rank = ACE, suit suit = SPADES, bool IsFaceUp = true);
        int GetValue() const;
        void Flip();

        friend std::ostream& operator<< (std::ostream& os, const Card& aCard);

    private:
        rank m_Rank; // номинал
        suit m_Suit; // масть
        bool m_IsFaceUp;
};
#endif
