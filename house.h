#ifndef HOUSE_H
#define HOUSE_H

#include "genericplayer.h"

class House : public GenericPlayer {
    public:
        House(const std::string& name = "House");

        virtual ~House();

        // Указывает, нужна ли игроку еще одна карта
        virtual bool IsHitting() const;

        // Переворачивает первую карту
        void FlipFirstCard();
};
#endif
