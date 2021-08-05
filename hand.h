#ifndef HAND_H
#define HAND_H
#include "card.h"
#include <vector>

class Hand
{
public:
    Hand() {m_Cards.reserve(7);}

    void Add(Card *pCard)
    {
        m_Cards.push_back(pCard);
    }
    void Clear()
    {
        std::vector<Card*>::iterator iter = m_Cards.begin();
        for (iter=m_Cards.begin(); iter!=m_Cards.end();++iter)
        {
           delete  *iter;
          *iter=0;
        }
        m_Cards.clear();
    }
    int GetValue() const
    {
        int sumVal=0;

        if (m_Cards.size() == 0)
            return 0;
        for (auto it = m_Cards.begin(); it != m_Cards.end(); ++it)
        {
           if (((*it)->getValue()==ACE)&&(m_Cards.size()>1)) sumVal+=11;
           else sumVal+=(*it)->getValue();
        }
       return sumVal;
    }
    int GetTotal() const
    {
        if (m_Cards.empty())
        {
            return 0;
        }
        if (m_Cards[0]->getValue()==0)
        {
            return 0;
        }
        int total=0;
        for (auto it = m_Cards.begin(); it != m_Cards.end(); ++it)
        {
            total+=(*it)->getValue();
        }
        bool containAce=false;
        for (auto it = m_Cards.begin(); it != m_Cards.end(); ++it)
        {
            if((*it)->getValue()==ACE) containAce=true;
        }
        if(containAce && total<=11)
            total+=10;
        return total;
    }
    ~Hand(){Clear();}
protected:
    std::vector <Card*> m_Cards;
};

#endif // HAND_H
