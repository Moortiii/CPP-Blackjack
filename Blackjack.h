//
// Created by Morten on 15.07.2018.
//

#ifndef BLACKJACK_BLACKJACK_H
#define BLACKJACK_BLACKJACK_H


#include <memory>
#include <vector>
#include "Card.h"
#include "Player.h"
#include "Dealer.h"

class Blackjack {
public:
    static int countHand(std::vector<std::shared_ptr<Card>> hand);
    static void determineWinner(const Player &player, const Dealer &dealer);

    static void playGame();
};


#endif //BLACKJACK_BLACKJACK_H
