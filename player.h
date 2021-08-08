#ifndef PLAYER_H
#define PLAYER_H

#include "genericplayer.h"

class Player : public GenericPlayer {
    public:
        Player(const std::string& name = "");

        virtual ~Player();

        // Указывает, нужна ли игроку еще одна карта
        virtual bool IsHitting() const;

        // игрок выиграл
        void Win() const;

        // игрок проиграл
        void Lose() const;

        // ничья
        void Push() const;
};
#endif // PLAYER_H
