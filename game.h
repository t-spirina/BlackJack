#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "house.h"
#include "deck.h"
// реализация игры
class Game {
    public:
        Game(const std::vector<std::string>& names);
        ~Game();
        void Play();
    private:
        Deck m_Deck; //колода карт
        House m_House; // рука дилера
        std::vector<Player> m_Players; //группа игроков-людей
};
#endif
