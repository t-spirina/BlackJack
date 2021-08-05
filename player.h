#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "GenericPlayer.h"
class Player : public GenericPlayer
{
public:
    Player(const std::string& name = "");
    virtual ~Player();
// показывает, хочет ли игрок продолжать брать карты
    virtual bool IsHitting() const
    {
        std::cout << m_name << ", do you want a hit? (Y/N): ";
        char response;
        std::cin >> response;
        return (response == 'y' || response == 'Y');
    };
// объявляет, что игрок победил
    void Win() const
    {
        std::cout << m_name << " wins\n";
    };
// объявляет, что игрок проиграл
    void Lose() const
    {
       std::cout << m_name << " loses\n";

    };
// объявляет ничью
    void Push() const
    {
        std::cout << m_name << " pushes.\n";
    };
};
#endif // PLAYER_H
