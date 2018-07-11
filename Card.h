#ifndef CARDGAME_CARD_H
#define CARDGAME_CARD_H

#include <string>

class Card {
public:
    void Print();
    friend std::ostream& operator<<(std::ostream& os, Card const& card);
    Card(int value, const std::string &suit);
public:
    const int value;
    const std::string suit;
};


#endif
