#include "board/board.h"
#include "ship/ship.h"
#include "utils/utils.h"
#include "coordinate/coordinate.h"
#include <iostream>


int main() {
    // Create a 5x5 board
    Board board(10, 10);
    std::vector<Ship> ships;
    int option;

    Ship destroyer1("Destroyer1", 2);
    Ship destroyer2("Destroyer2", 2);
    Ship submarine("Submarine", 3);
    Ship cruiser("Cruiser", 4);
    Ship carrier("Carrier", 5);

    ships.push_back(carrier);
    ships.push_back(cruiser);
    ships.push_back(submarine);
    ships.push_back(destroyer2);
    ships.push_back(destroyer1);

    std::cout << "Choose one of the following options " << std::endl;
    std::cout << "Option 1: Place ships manually \nOption 2: Place ships automatically" << std::endl;
    std::cin >> option;

    if(option==1){
        int x,y;
        char orientation;
        board.display(false);
        
        do{
            std::cout << "Enter x, y, orientation for Destroyer 1 " << std::endl;
            std::cin >> x >> y >> orientation;
        }while(!board.placeShip(destroyer1, x, y, orientation));

        board.display(false);
        
        do{
            std::cout << "Enter x, y, orientation for Destroyer 2 " << std::endl;
            std::cin >> x >> y >> orientation;
        }while(!board.placeShip(destroyer2, x, y, orientation));

        board.display(false);
        
        do{
            std::cout << "Enter x, y, orientation for submarine " << std::endl;
            std::cin >> x >> y >> orientation;
        }while(!board.placeShip(submarine, x, y, orientation));

        board.display(false);
        
        do{
            std::cout << "Enter x, y, orientation for cruiser " << std::endl;
            std::cin >> x >> y >> orientation;
        }while(!board.placeShip(cruiser, x, y, orientation));

        board.display(false);
        
        do{
            std::cout << "Enter x, y, orientation for carrier " << std::endl;
            std::cin >> x >> y >> orientation;
        }while(!board.placeShip(carrier, x, y, orientation));

    }else if(option==2){
        placeShipsRandomly(board, ships);
    }

    // Display board (own view)
    board.display(false);

    // Display opponent board view
    board.display(true);

    return 0;
}