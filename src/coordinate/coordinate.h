#ifndef COORDINATES_H
#define COORDINATES_H

#include "../ship/ship.h"

class Coordinate {
    private:
        char symbol;
        Ship* ship;
        int row;
        int col;

    public:
        Coordinate(char symbol, int row, int col);

        void set_ship(Ship* ship);

        char get_symbol();

        void set_symbol(char symbol);

        Ship* get_ship();
};

#endif