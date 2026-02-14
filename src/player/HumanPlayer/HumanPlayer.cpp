#include "player/HumanPlayer/HumanPlayer.h"
#include "board/board.h"
#include <string>
#include <vector>
#include <iostream>

// Take coordinate input and attack on opponents board
void HumanPlayer::makeMove(Board &opponentBoard){
    int row, col;
    do{
        std::cout << "Enter coordinates (row col) to attack : ";
        std::cin >> row >> col ;
    }while(opponentBoard.isHit(row,col));

    std::string result = opponentBoard.recordAttack(row,col);
    std::cout << result << std::endl;
}

void HumanPlayer::placeShips(Board &selfBoard) {
    int option;
    std::cout << "Your turn to place ships " << std::endl;
    std::cout << "Choose one of the following options " << std::endl;
    std::cout << "Option 1: Place ships manually \nOption 2: Place ships automatically" << std::endl;
    std::cin >> option;

    if(option==1){
        int x,y;
        char orientation;

        for(Ship& ship:selfBoard.get_ships()){
            int x,y;
            char orientation;
            selfBoard.display(false);
            do{
                std::cout << "Enter x, y, orientation for " << ship.get_name() << std::endl;
                std::cin >> x >> y >> orientation;
            }while(!selfBoard.placeOneShip(ship, x, y, orientation));
        }

        selfBoard.display(false);
    }else if(option==2){
        selfBoard.placeAllShips();
        selfBoard.display(false);
    }
}