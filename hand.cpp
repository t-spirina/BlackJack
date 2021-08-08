#include "hand.h"

Hand::Hand()
{
    m_Cards.reserve(7);
}

Hand::~Hand()
{
    Clear();
}

// Добавляет карту в руку. Добавляет указатель на объект типа Сard в вектор m_Сards
void Hand::Add(Card *pCard)
{
    m_Cards.push_back(pCard);
}

// Очищает руку от карт.
void Hand::Clear()
{
    // Удаляет все указатели из вектора m_Сards, устраняя все связанные с ними объекты в куче
    std::vector<Card*>::iterator iter = m_Cards.begin();
    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
    {
        delete *iter;
        *iter = 0;
    }
    m_Cards.clear();
}

// Возвращает сумму очков карт руки
int Hand::GetTotal() const
{
    // если в руке нет карт - return 0
    if (m_Cards.empty())
    {
        return 0;
    }

    // если карта рубашкой вверх - return 0
    if (m_Cards[0] -> GetValue() == 0)
    {
        return 0;
    }

    // вычисление суммы всех карт. Пока считаю, что туз=1
    int total = 0;
    std::vector<Card*>::const_iterator iter;
    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
    {
        total += (*iter) -> GetValue();
    }

    //определяем, есть ли в руке туз
    bool containsAce = false;
    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
    {
        if ((*iter) -> GetValue() == Card::ACE)
        {
            containsAce = true;
        }
    }

    // если туз есть, то он дает 11 очков.
    if (containsAce && total <= 11)
    {
        // т.к. раньше туз уже был засчитан за 1, добавляю 10
        total += 10;
    }

    return total;
}
