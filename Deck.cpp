#include <bits/uses_allocator.h>
#include <algorithm>
#include <random>
#include <chrono>
#include <memory>
#include "Deck.h"

void Deck::add(Card const& card) {
    cards.push_back(std::make_shared<Card>(card));
}

void Deck::remove(Card &card) {
    cards.erase(cards.begin());
}

void Deck::shuffle() {
    std::shuffle(cards.begin(), cards.end(), std::default_random_engine{ unsigned(std::chrono::system_clock::now().time_since_epoch().count()) });
}

std::shared_ptr<Card>& Deck::draw() {
    return *cards.begin();
}

void Deck::create() {
    std::string suits[] = { "Diamonds", "Clubs", "Hearts", "Spades" };

    for(std::string const& suit : suits) {
        for(int i = 0; i < 13; i++) {
            Deck::add(Card(i + 1, suit));
        }
    }
}
