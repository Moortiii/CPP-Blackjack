#include <iostream>
#include "Blackjack.h"
#include "Dealer.h"

int Blackjack::countHand(std::vector<std::shared_ptr<Card>> hand) {
    int sum = 0;
    int aces = 0;

    // Assume all aces are played as 11 then deduct as necessary
    for(auto const& card  : hand)
        card->value == 1 ? aces++ : sum += card->value;

    sum += (aces * 11);

    for(unsigned int i = 0; i < aces; i++) {
        if(sum > 21)
            sum -= 10;
    }

    return sum;
}

void Blackjack::playGame() {
    Deck deck;
    Player player("Morten");
    Dealer dealer("Dealer");

    dealer.deal(player, deck);
    dealer.prompt(player, deck);

    Blackjack::determineWinner(player, dealer);
}

void Blackjack::determineWinner(Player const& player, Dealer const& dealer) {
    using std::cout;
    using std::endl;

    int playerSum = Blackjack::countHand(player.hand);
    int dealerSum = Blackjack::countHand(dealer.hand);

    std::cout << "Player: " << playerSum << std::endl;
    std::cout << "Dealer: " << dealerSum << std::endl;

    if(playerSum > 21) {
        if(dealerSum > 21)
            cout << "Both you and the dealer bust, you win!" << endl;
        else if(dealerSum < 21)
            cout << "You bust, dealer wins!" << endl;
        else if(dealerSum == 21)
            cout << "You bust, dealer wins with blackjack!" << endl;
    } else if(playerSum < 21) {
       if(dealerSum > 21)
           cout << "Dealer busts, you win!" << endl;
       else if(dealerSum == 21)
           cout << "Dealer wins with blackjack!" << endl;
       else if(dealerSum < 21) {
           if(dealerSum < playerSum)
               cout << "You win with the highest sum!" << endl;
           else if(dealerSum > playerSum)
               cout << "Dealer wins with the highest sum!" << endl;
           else if(dealerSum == playerSum)
               cout << "It's a tie!" << endl;
       }
    } else if(playerSum == 21) {
        if(dealerSum == 21)
            cout << "Both you and the dealer have blackjack, you win!" << endl;
        else if(dealerSum > 21)
            cout << "Dealer busts, you win with blackjack!" << endl;
        else if(dealerSum < 21)
            cout << "You win with blackjack!" << endl;
    }

    int play = 0;
    std::cout << "Do you want to play again? Y(1) / N(0)" << std::endl;
    std::cin >> play;

    if(play)
        playGame();

    std::cout << "Thank you for playing!" << std::endl;
}
