#ifndef HOUSES_H
#define HOUSES_H
#include<iostream>
#include "GenericPlayer.h"

class House : public GenericPlayer
{
public:
    House(const std::string& name = "House");
    virtual ~House();
// показывает, хочет ли дилер продолжать брать карты
    virtual bool IsHitting() const{return (GetTotal() <= 16);};
// переворачивает первую карту
    void FlipFirstCard()
    {
        if (!(m_Cards.empty()))
        {
            m_Cards[0]->Flip();
        }
        else
        {
            std::cout << "No card to flip!\n";
        }
    };
};
#endif // HOUSES_H
