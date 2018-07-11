#include <iostream>
#include <vector>
#include "Deck.h"
#include "Player.h"

// TODO: Create separate class for Dealer
void declareWinner(Player const& player, Player const& dealer);
void promptToHit(Player& player, Player const& dealer, Deck& deck);

int main() {
    Player player("Player");
    Player dealer("Dealer");
    Deck deck;

    // Setup
    deck.create();
    deck.shuffle();

    // Play
    player.hit(deck);
    dealer.hit(deck);
    player.hit(deck);
    dealer.hit(deck);

    /*

    Card card_1(1, "Diamonds");
    Card card_3(1, "Clubs");
    Card card_2(11, "Spades");
    player.hit(deck, std::make_shared<Card>(card_1));
    player.hit(deck, std::make_shared<Card>(card_2));
    player.hit(deck, std::make_shared<Card>(card_3));

    */

    player.printHand();
    dealer.printHand();

    promptToHit(player, dealer, deck);
    return 0;
}

void declareWinner(Player const& player, Player const& dealer) {
    if(player.countHand() == 21) {
        if(dealer.countHand() == 21) {
            std::cout << "Both dealer and player have blackjack, player wins!" << std::endl;
        } else if(dealer.countHand() > 21) {
            std::cout << "Player wins with blackjack, dealer busts!" << std::endl;
        } else if(dealer.countHand() < 21) {
            std::cout << "Player wins with blackjack!" << std::endl;
        }
    } else if(player.countHand() > 21) {
        if(dealer.countHand() == 21) {
            std::cout << "Dealer wins with blackjack, player busts!" << std::endl;
        } else if(dealer.countHand() > 21) {
            std::cout << "Both player and dealer bust, player wins!" << std::endl;
        } else if(dealer.countHand() < 21) {
            std::cout << "Dealer has the highest sum, player busts!" << std::endl;
        }
    } else if(player.countHand() < 21) {
        if(dealer.countHand() == 21) {
            std::cout << "Dealer wins with blackjack, player busts!" << std::endl;
        } else if(dealer.countHand() > 21) {
            std::cout << "Dealer busts, player wins!" << std::endl;
        } else if(dealer.countHand() < 21) {
            if(player.countHand() > dealer.countHand()) {
                std::cout << "Player wins with the highest sum!" << std::endl;
            } else if(player.countHand() < dealer.countHand()) {
                std::cout << "Dealer wins with the highest sum!" << std::endl;
            }
        }
    }
}

void promptToHit(Player& player, Player const& dealer, Deck& deck) {
    player.printHand();
    int staying = 0;
    std::cout << "Hit? (0) / Stay? (1)" << std::endl;
    std::cin >> staying;

    // TODO: Error checking, exception handling
    if(staying == 0) {
        player.hit(deck);
        if(player.countHand() < 21) {
            promptToHit(player, dealer, deck);
        } else {
            declareWinner(player, dealer);
        }
    } else {
        std::cout << "You have chosen to stay." << std::endl;
        declareWinner(player, dealer);
    }
}