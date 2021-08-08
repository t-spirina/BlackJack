#ifndef HAND_H
#define HAND_H

#include <vector>
#include "card.h"
//Набор карт, коллекция объектов класса Card
class Hand {
    public:
        Hand();
        virtual ~Hand();
        void Add(Card *pCard); //Добавляет карту в руку. Добавляет указатель на объект типа Сard в вектор m_Сards
        void Clear(); //Очищает руку от карт.
        int GetTotal() const;//Возвращает сумму очков карт руки
    protected:
        std::vector <Card*> m_Cards; //Коллекция карт
};
#endif
