#ifndef GENERICPLAYER_H
#define GENERICPLAYER_H

#include "hand.h"
/*
Обобщенно описывает игрока.
Не является полноценным игроком, а лишь содержит элементы,
характерные как для игрока-человека, так и для игрока-компьютера
*/
class GenericPlayer : public Hand {
    friend std::ostream& operator<< (std::ostream& os, const GenericPlayer& aGenericPlayer);

    public:
        GenericPlayer(const std::string& name = "");

        virtual ~GenericPlayer();

        // Указывает, нужна ли игроку еще одна карта
        virtual bool IsHitting() const = 0;

        // Указывает, что у игрока перебор
        bool IsBusted() const;

        // Объявляет, что у игрока перебор
        void Bust() const;

    protected:
        std::string m_Name; // имя игрока
};

#endif // GENERICPLAYER_H
