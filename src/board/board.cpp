#include "board.h"
#include <iostream>
#include <random>
#include "../coordinate/coordinate.h"

// Constructor
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
}


bool Board::placeShip(Ship &ship, int x_, int y_, char orientation){
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

    ships.push_back(&ship);
    return true;
}




// update board, find which ship it is, register hit in that ship.
void Board::recordAttack(int x, int y){
    if(grid[x][y].get_symbol()=='.') grid[x][y].set_symbol('O');
    else if (grid[x][y].get_symbol() == 'S'){
        grid[x][y].set_symbol('X');
        grid[x][y].get_ship()->hit_position(x,y);
    }
}

// Returns if all ship are sunk so checks for game over condition.
bool Board::allShipsSunk() {
    for(int i=0;i<ships.size();i++){
        if(!ships[i]->isSunk()) return false;
    }
    return true;
}

// Returns if a grid coordinate is already hit (it can be ship/miss/hit)
bool Board::isHit(int x, int y){
    return grid[x][y].get_symbol() != '.';
}

// Displays the board either with ships location (for self) or without ships only showing hit/miss (for opponent).
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

// Returns th grid
std::vector<std::vector<Coordinate> > Board::get_grid(){
    return grid;
}

int Board::get_cols(){
    return cols;
}

int Board::get_rows(){
    return rows;
}

std::vector<Ship*> Board::get_ships(){
    return ships;
}