#ifndef BLACKJACK_CARD_H
#define BLACKJACK_CARD_H


#include <string>

class Card {
public:
    const int number;
    const int value;
    std::string const suit;

public:
    Card(const std::string &suit, int number);
};

#endif