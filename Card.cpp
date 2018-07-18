#include <iostream>
#include "Card.h"

Card::Card(std::string const &suit, int number) : suit(suit),
                                                  number(number),
                                                  value(number > 10 ? 10 : number)

{
    std::cout << "CARD::CREATED -> " << number << " of " << suit << std::endl;
}
