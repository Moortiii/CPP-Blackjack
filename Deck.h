#ifndef CARDGAME_DECK_H
#define CARDGAME_DECK_H

#include <vector>
#include <memory>
#include "Card.h"

class Deck {
public:
    std::vector<std::shared_ptr<Card>> cards;
public:
    void add(Card const& card);
    void remove(Card& card);
    void create();
    std::shared_ptr<Card>& draw();
    void shuffle();
};


#endif
