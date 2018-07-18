#ifndef BLACKJACK_DEALER_H
#define BLACKJACK_DEALER_H


#include <string>
#include <memory>
#include <vector>
#include "Card.h"
#include "Deck.h"
#include "Player.h"

class Dealer {
public:
    std::string const name;
    std::vector<std::shared_ptr<Card>> hand;
public:
    void hit(Deck& deck);
    void deal(Player& player, Deck& deck);
    explicit Dealer(std::string const& name);
    void prompt(Player &player, Deck &deck);
};

#endif
