#include <iostream>
#include "Ship.h"

int main()
{
    Ship cruiser("Cruiser", 4, "horizontal");

    std::vector<std::pair<int,int>> pos = {{0,0}, {0,1}, {0,2},{0,3}};
    cruiser.place_of_ship(pos);

    cruiser.hit_position(0,0);
    cruiser.hit_position(0,1);
    cruiser.hit_position(0,2);
    cruiser.hit_position(0,3);

    if(cruiser.isSunk())
        std::cout << "Ship sunk!\n";
    else
        std::cout << "Ship still alive!\n";

    return 0;
}
