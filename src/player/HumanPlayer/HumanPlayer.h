#ifndef HUMAN_PLAYER_H
#define HUMAN_PLAYER_H

#include "player/player.h"
#include "board/board.h"

class HumanPlayer: Player {
    public:
        void makeMove(Board &opponentBoard);
        void placeShips(Board &selfBoard);
};

#endif