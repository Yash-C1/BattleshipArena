#ifndef CPU_PLAYER_H
#define CPU_PLAYER_H

#include "player/player.h"
#include "board/board.h"

class CPUPlayer: Player {
    public:
        void makeMove(Board &opponentBoard);
        void placeShips(Board &selfBoard);
};

#endif