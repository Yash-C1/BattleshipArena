#include "board/board.h"
#include "ship/ship.h"
#include "coordinate/coordinate.h"
#include "player/HumanPlayer/HumanPlayer.h"
#include "player/CPUplayer/CPUplayer.h"
#include <iostream>


int main() {
    // Create a 10x10 board
    Board HumanPlayerBoard(10, 10);
    Board CPUPlayerBoard(10, 10);

    HumanPlayer p1;
    CPUPlayer p2;
    
    p1.placeShips(HumanPlayerBoard);
    p2.placeShips(CPUPlayerBoard);

    do{
        std::cout << "Player 1 move -" << std::endl;
        p1.makeMove(CPUPlayerBoard);
        HumanPlayerBoard.display(false);
        CPUPlayerBoard.display(true);

        std::cout << "CPU move -" << std::endl;
        p2.makeMove(HumanPlayerBoard);
        HumanPlayerBoard.display(false);
        CPUPlayerBoard.display(true);
    }while(!CPUPlayerBoard.allShipsSunk() && !HumanPlayerBoard.allShipsSunk());

    return 0;
}