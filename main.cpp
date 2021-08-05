#include <iostream>
#include "hand.h"


int main()
{
    Hand h;
    Card c1(HEARTS,ACE);
    Card c3(DIAMONDS,QUEEN);
    h.Add(&c1);
    h.Add(&c3);
    std::cout<<"hand "<<h.GetValue()<<std::endl;
    return 0;
}
