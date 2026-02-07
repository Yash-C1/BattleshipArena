#ifndef BOARD_H
#define BOARD_H

#include "../ship/ship.h"
#include <vector>
#include "../coordinate/coordinate.h"

class Board {
    private:
        std::vector<std::vector<Coordinate> > grid;  // '*' for empty, 'S' for ship, 'X' for hit, 'O' for miss
        std::vector<Ship*> ships;
        int rows;
        int cols;
        
    public:
        Board(int row, int col);

        // void placeShip(Ship& ship, int x, int y, char orientation);
        bool placeShip(Ship& ship, int x, int y, char orientation);

        
        bool isHit(int x, int y);

        bool allShipsSunk();

        void recordAttack(int x, int y);

        void display(bool hideShips);

        int get_rows();

        int get_cols();

        std::vector<Ship*> get_ships();

        std::vector<std::vector<Coordinate> > get_grid();
};

#endif