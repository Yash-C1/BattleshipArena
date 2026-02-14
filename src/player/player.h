#ifndef PLAYER_H
#define PLAYER_H

#include "board/board.h"

class Player { 
    public:
        virtual void makeMove(Board &board) = 0;
        virtual void placeShips(Board &board) = 0;
};

#endif