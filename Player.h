//
// Created by Morten on 10.07.2018.
//

#ifndef CARDGAME_PLAYER_H
#define CARDGAME_PLAYER_H

#include <vector>
#include <memory>
#include "Card.h"
#include "Deck.h"

class Player {
public:
    std::vector<std::shared_ptr<Card>> hand;
    const std::string name;
    void hit(Deck& deck);
    Player(std::string const& name);
    void printHand() const;
    int countHand() const;
    int countAces() const;

    void hit(Deck &deck, const std::shared_ptr<Card> &card);
};

#endif //CARDGAME_PLAYER_H
