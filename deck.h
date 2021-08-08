#ifndef DECK_H
#define DECK_H
#include <algorithm>
#include "hand.h"
#include "genericplayer.h"
//Имеет дополнительную функциональность, которая отсутствует в классе Hand — тасование и раздачу
class Deck : public Hand {
    public:
        Deck();
        virtual ~Deck();
        // создание колоды из 52 карт
        void Populate();
        // перемешать карты в колоде
        void Shuffle();
        // сдать карту в руку
        void Deal(Hand& aHand);
        // сдать дополнительную карту игроку
        void AdditionalCards(GenericPlayer& aGenericPlayer);
};

#endif // DECK_H
