#ifndef BLACKJACK_PLAYER_H
#define BLACKJACK_PLAYER_H

#include <string>
#include <memory>
#include <vector>
#include "Card.h"
#include "Deck.h"

class Player {
public:
    explicit Player(std::string const& name);
    void hit(Deck& deck);
public:
    std::string const name;
    std::vector<std::shared_ptr<Card>> hand;

    void print();
};

#endif
