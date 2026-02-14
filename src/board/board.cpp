#include "board.h"
#include <iostream>
#include <random>
#include <vector>
#include <string>
#include "coordinate/coordinate.h"
#include "ship/ship.h"


Board::Board(int rows, int cols){
    this->rows = rows;
    this->cols = cols;

    grid.resize(rows);
    for (int i = 0; i < rows; i++) {
        grid[i].reserve(cols);
        for (int j = 0; j < cols; j++) {
            grid[i].push_back(Coordinate('.', i, j));
        }
    }

    ships.emplace_back("Destroyer 1",2);
    ships.emplace_back("Destroyer 2",2);
    ships.emplace_back("Submarine",3);
    ships.emplace_back("Cruiser",4);
    ships.emplace_back("Carrier",5);
}


bool Board::placeOneShip(Ship &ship, int x_, int y_, char orientation){
    static std::mt19937 rng(std::random_device{}());
    int size = ship.get_size();
    std::vector<std::pair<int,int> > positions;
    int x,y;

    if(orientation=='H'){
    
        x = (x_ >= 0 ) ? x_ : std::uniform_int_distribution<>(0, rows - 1)(rng);
        y = (y_ >= 0) ? y_ : std::uniform_int_distribution<>(0, cols - ship.get_size())(rng);
        for(int i=0;i<size;i++){
            if(y+size>cols || grid[x][y+i].get_symbol() !='.'){
                return false;
            }else{
                positions.push_back({x,y+i});
            }
        }
        ship.place_of_ship(positions);
    }else{
        x = (x_ >= 0 ) ? x_ : std::uniform_int_distribution<>(0, rows - ship.get_size())(rng);
        y = (y_ >= 0) ? y_ : std::uniform_int_distribution<>(0, cols - 1)(rng);
        for(int i=0;i<size;i++){
            if(x+size>rows || grid[x+i][y].get_symbol() !='.'){
                return false;
            }else{
                positions.push_back({x+i,y});
            }
        }
        ship.place_of_ship(positions);
    }

    for(int i=0;i<size;i++){
        grid[positions[i].first][positions[i].second].set_symbol('S');
        grid[positions[i].first][positions[i].second].set_ship(&ship);
    }

    return true;
}



void Board::placeAllShips(){
    static std::mt19937 rng(std::random_device{}());

    for(Ship& ship: ships){
        const int MAX_ATTEMPTS = 10000;
    
        for (int attempt = 0; attempt < MAX_ATTEMPTS; attempt++) {
            char orientation = (std::uniform_int_distribution<>(0,1)(rng) == 0) ? 'H' : 'V';
            if(!placeOneShip(ship, -1,-1,orientation))continue;
            else break;
        }
    }
}



std::string Board::recordAttack(int x, int y){
    if(grid[x][y].get_symbol()=='.') {
        grid[x][y].set_symbol('O');
        return "It's a Miss!";
    }else if (grid[x][y].get_symbol() == 'S'){
        grid[x][y].set_symbol('X');
        grid[x][y].get_ship()->hit_position(x,y);
        return grid[x][y].get_ship()->isSunk() ? "Ship Sunk!" : "It's a hit!";
    }
    return "";
}



bool Board::allShipsSunk() {
    for(int i=0;i<ships.size();i++){
        if(!ships[i].isSunk()) return false;
    }
    return true;
}


bool Board::isHit(int x, int y){
    return grid[x][y].get_symbol() == 'O' || grid[x][y].get_symbol() == 'X';
}


void Board::display(bool hideShips){
    if(hideShips) std::cout << "    Opponent board" << std::endl;
    else std::cout << "      Your board" << std::endl;

    std::cout << "  " ;
    for(int j=0;j<cols;j++){
        std::cout << j << " ";
    }
    std::cout << std::endl;
    for(int i=0;i<rows;i++){
        std::cout << i << " " ;
        for(int j=0;j<cols;j++){
            if(grid[i][j].get_symbol() == 'S' && hideShips) std::cout << '.' << " " ;
            else std::cout << grid[i][j].get_symbol() << " " ;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}


// Adding colors to terminal output
// void Board::display(bool hideShips)
// {
//     const std::string RESET  = "\033[0m";
//     const std::string YELLOW = "\033[33m";
//     const std::string RED    = "\033[31m";
//     const std::string BLUE   = "\033[34m";

//     if(hideShips) std::cout << "    Opponent board\n";
//     else std::cout << "      Your board\n";

//     std::cout << "  ";
//     for(int j = 0; j < cols; j++) std::cout << j << " ";
//     std::cout << "\n";

//     for(int i = 0; i < rows; i++) {
//         std::cout << i << " ";
//         for(int j = 0; j < cols; j++) {
//             char symbol = grid[i][j].get_symbol();

        // For colored symbols ---
         
//             // if (hideShips && symbol == 'S')
//             //     std::cout << ". ";
//             // else if (symbol == 'S')
//             //     std::cout << YELLOW << "S" << RESET << " ";
//             // else if (symbol == 'X')
//             //     std::cout << RED << "X" << RESET << " ";
//             // else if (symbol == 'O')
//             //     std::cout << BLUE << "O" << RESET << " ";
//             // else
//             //     std::cout << ". ";

        // For colored blocks ---

//             if (hideShips && symbol == 'S') {
//                 std::cout << ". ";
//             }
//             else if (symbol == 'S') {
//                 // Ship body → continuous yellow bar
//                 std::cout << "\033[43m  \033[0m";
//             }
//             else if (symbol == 'X') {
//                 // Hit → red background
//                 std::cout << "\033[41m  \033[0m";
//             }
//             else if (symbol == 'O') {
//                 // Miss → blue background
//                 std::cout << "\033[44m  \033[0m";
//             }
//             else {
//                 std::cout << ". ";
//             }
//         }
//         std::cout << "\n";
//     }

//     std::cout << "\n";
// }

int Board::get_cols(){
    return cols;
}


int Board::get_rows(){
    return rows;
}


std::vector<Ship>& Board::get_ships(){
    return ships;
}