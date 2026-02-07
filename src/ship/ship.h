#ifndef SHIP_H
#define SHIP_H

#include <string>
#include <vector>
#include <utility>

class Ship {

private:
    std::string name;  //(destroyer-2, submarine-3, cruiser-4, carrier-5)
    int size;
    std::vector<std::pair<int,int> > positions;
    std::vector<bool> hits;


public:
    
    //const is use for faster copying data
    // Constructor
    Ship(const std::string &name, int size);

    // set coordinates ship
    void place_of_ship(const std::vector<std::pair<int,int> >& positions);

    // Check if a cell belongs to this ship
    bool cellOccupied(int x, int y) const;

    // Register a hit
    void hit_position(int x, int y);

    // Check if ship is sunk
    bool isSunk() const;

    // returns size of ship
    int get_size();
};

#endif