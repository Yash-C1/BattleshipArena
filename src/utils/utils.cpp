#include "utils.h"
#include <iostream>
#include "../board/board.h"
#include "../ship/ship.h"
#include <vector>
#include <random>

void placeShipsRandomly(Board &board, std::vector<Ship> &ships) {

    static std::mt19937 rng(std::random_device{}());
    // bool canPlace = true;


    // This vector contains the ship sizes.
    // We will place ship of size 5 first (top) and then remove it then the next one of size 4 ...
    // std::vector<int> shipsToPlace = {5,4,3,2,2};

    for(Ship ship: ships){
        const int MAX_ATTEMPTS = 10000;
    
        for (int attempt = 0; attempt < MAX_ATTEMPTS; attempt++) {
            char orientation = (std::uniform_int_distribution<>(0,1)(rng) == 0) ? 'H' : 'V';
            // int x,y;
            // if (orientation == 'H') {
            //     x = std::uniform_int_distribution<>(0, board.get_rows() - 1)(rng);
            //     y = std::uniform_int_distribution<>(0, board.get_cols() - ship->get_size())(rng);
            //     for(int i=0;i<ship->get_size();i++){
            //         if(board.get_grid()[x][y+i].get_symbol()!='.') {
            //             std::cout << "Ships cannot be randomly placed. Please place ships manually.";
            //             canPlace = false;
            //             break;
            //         }
            //     }
            //     if(canPlace) board.placeShip(*ship, x,y,orientation);
            //     else continue;

            // } else {
            //     x = std::uniform_int_distribution<>(0, board.get_rows() - ship->get_size())(rng);
            //     y = std::uniform_int_distribution<>(0, board.get_cols() - 1)(rng);
            //     for(int i=0;i<ship->get_size();i++){
            //         if(board.get_grid()[y][x+i].get_symbol()!='.') {
            //             std::cout << "Ships cannot be randomly placed. Please place ships manually.";
            //             canPlace = false;
            //             break;
            //         }
            //     }
            //     if(canPlace) board.placeShip(*ship, x,y,orientation);
            //     else continue;
            // }

            if(!board.placeShip(ship, -1,-1,orientation))continue;
            else break;
        }
    }
}