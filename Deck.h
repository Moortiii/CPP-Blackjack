#ifndef BLACKJACK_DECK_H
#define BLACKJACK_DECK_H


#include <vector>
#include <memory>
#include <random>
#include <chrono>
#include "Card.h"

class Deck {
public:
    std::vector<std::shared_ptr<Card>> cards;
    std::default_random_engine engine;
    long long int seed = std::chrono::system_clock::now().time_since_epoch().count();
public:
    Deck();
    std::shared_ptr<Card> draw();
    void discard();
    void shuffle();
};

#endif
