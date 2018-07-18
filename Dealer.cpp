#include <iostream>
#include "Dealer.h"
#include "Blackjack.h"

void Dealer::hit(Deck &deck) {
    auto card = deck.draw();
    deck.discard();
    hand.push_back(card);
}

// Deal two cards to the dealer and player in the correct order
void Dealer::deal(Player &player, Deck &deck) {
    std::cout << std::endl;

    player.hit(deck);
    this->hit(deck);
    player.hit(deck);
    this->hit(deck);

    player.print();
    std::cout << "Dealer's first card is: " << hand.begin()->get()->value << " of " << hand.begin()->get()->suit << std::endl;
}

// Allow the player to keep hitting until they bust or choose to stay
void Dealer::prompt(Player& player, Deck& deck) {
    int staying = 0;

    std::cout << "Do you wish to hit (1) or stay (0)?" << std::endl;
    std::cin >> staying;

    if(staying) {
        player.hit(deck);
        player.print();
        if(Blackjack::countHand(player.hand) < 21)
            prompt(player, deck);
    }

    while(Blackjack::countHand(this->hand) < 17) {
        this->hit(deck);
    }
}

Dealer::Dealer(std::string const& name) : name(name) {
    std::cout << "DEALER::CREATED-> " << name << std::endl;
};