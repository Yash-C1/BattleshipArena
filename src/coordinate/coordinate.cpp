#include "coordinate.h"
#include <iostream>


// Constructor
Coordinate::Coordinate(char symbol, int x, int y){
    this->symbol = symbol;
    this->ship = nullptr;
    this->row = x;
    this->col = y;
}

void Coordinate::set_ship(Ship* ship){
    this->ship = ship;
}

char Coordinate::get_symbol(){
    return symbol;
}

void Coordinate::set_symbol(char symbol){
    this->symbol = symbol;
}

Ship* Coordinate::get_ship() {
    return ship;
}