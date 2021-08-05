#ifndef GENERICPLAYER_H
#define GENERICPLAYER_H
#include <iostream>
#include <vector>
#include "hand.h"

class GenericPlayer:public Hand
{
public:
    GenericPlayer(const std::string& name=""): m_name(name) {};
    virtual bool IsHitting() const =0;
    bool IsBusted() const{ return (GetTotal()>21);};
    void Bust() const {std::cout<<m_name<< " busts" <<std::endl;};
    friend std::ostream& operator<<(std::ostream& os, const GenericPlayer& aGenericPlayer);
    virtual ~GenericPlayer();
protected:
    const std::string m_name;

};
std::ostream& operator<<(std::ostream& os, const GenericPlayer& aGenericPlayer)
{
    os << aGenericPlayer.m_name << ":\t";
    std::vector<Card*>::const_iterator pCard;
    if (!aGenericPlayer.m_Cards.empty())
    {
        for (pCard = aGenericPlayer.m_Cards.begin();
            pCard != aGenericPlayer.m_Cards.end();
            ++pCard)
       {
           os << *(*pCard) << "\t";
       }
       if (aGenericPlayer.GetTotal() != 0)
       {
              std::cout << "(" << aGenericPlayer.GetTotal() << ")";
       }
    }
    else
    {
        os << "<empty>";
    }
    return os;
}

#endif // GENERICPLAYER_H
