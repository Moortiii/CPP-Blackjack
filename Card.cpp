#include <iostream>
#include "Card.h"

void Card::Print() {
    std::cout << value << " of " << suit << std::endl;
}

std::ostream& operator<<(std::ostream& os, Card const& card) {
    os << card.value << " of " << card.suit;
    return  os;
}

Card::Card(int value, std::string const& suit) : suit(suit), value(value) {
    std::cout << "Created " << value << " of " << suit << std::endl;
}

