//
// Created by Morten on 10.07.2018.
//

#include <iostream>
#include "Player.h"

void Player::hit(Deck &deck) {
    auto card = deck.draw();
    std::cout << name << " drew the " << *card << std::endl;
    hand.push_back(card);
    deck.remove(*card);
}

void Player::hit(Deck& deck, std::shared_ptr<Card> const& card) {
    hand.push_back(card);
    deck.remove(*card);
}

void Player::printHand() const {
    std::cout << std::endl << name << " hand:" << std::endl;

    for(auto const& card : hand) {
        std::cout << *card << std::endl;
    }

    std::cout << "Sum: " << countHand() << std::endl;
}

int Player::countAces() const {
    int aceCount = 0;

    for(auto const& card : hand) {
        if(card->value == 1) {
            aceCount++;
        }
    }

    return aceCount;
}

int Player::countHand() const {
    int aceCount = countAces();
    int sum = 0;

    // First assume all the aces count as 11, but subtract one so they're only counted once
    sum += (10 * aceCount);

    for(auto const& card : hand)
        card->value >= 10 ? sum += 10 : sum += card->value;

    for(int i = 0; i < aceCount; i++) {
        if(sum > 21)
            sum -= 10;
    }

    return sum;
}

Player::Player(std::string const &name) : name(name) {
    std::cout << "PLAYER::CREATED" << std::endl;
}
