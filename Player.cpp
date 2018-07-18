#include <iostream>
#include "Player.h"
#include "Blackjack.h"

Player::Player(std::string const& name) : name(name) {
    std::cout << "PLAYER::CREATED-> " << name << std::endl;
}

void Player::hit(Deck &deck) {
    auto card = deck.draw();
    deck.discard();
    hand.push_back(card);
}

void Player::print() {
    std::cout << "Player hand: " << std::endl;

    for(auto const& card : hand)
        std::cout << card->value << " of " << card->suit << std::endl;

    std::cout << "Sum: " << Blackjack::countHand(hand) << std::endl << std::endl;
}