#include <algorithm>
#include "Deck.h"

Deck::Deck() {
    std::string const suits[] = { "Diamonds", "Spades", "Clubs", "Hearts" };

    for(auto const& suit : suits) {
        for(int i = 0; i < 13; i++)
            cards.push_back(std::make_shared<Card>(Card(suit, (i + 1))));
    }

    engine.seed(unsigned(seed));
    shuffle();
}

// We always draw from the top of the deck
std::shared_ptr<Card> Deck::draw() {
    return *cards.begin();
}

// TODO: Drawing and discarding should be done at the same time
// And we always erase the top card after drawing it
void Deck::discard() {
    cards.erase(cards.begin());
}

// Shuffle the deck using a seed based on the the value of the system clock when the game was started
void Deck::shuffle() {
    std::shuffle(cards.begin(), cards.end(), engine);
}
