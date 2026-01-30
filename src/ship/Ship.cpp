#include<iostream>
using namespace std;

class Ship{

    private:
    string name; //ship type (destroyer - 2, submarine-3, Cruiser - 4, carrier-5)
    int size;
    vector<pair<int,int>>positions;
    vector<bool>hits; //

    public:

    Ship(string name, int size);
    //ship where it placed(exists)
    void place_of_ship(const vector<pair<int, int>> &positions);
    
    bool cellOccupied(int x,int y);

    void hit_position(int x, int y);
    bool isSunk();

};

Ship::Ship(string name, int size){
    this->name = name;
    this->size = size;
    
}
void Ship::place_of_ship(const vector<pair<int,int>> &positions){
    this->positions = positions;
}

//check  if cell belongs to perticular ship or its water
bool Ship::cellOccupied(int x,int y)
{
    //
    for(auto p: positions){
        if(p.first == x && p.second == y){
            return true;
        }
    }
    return false;
}

//we have to mark hit on the ship
void Ship::hit_position(int x, int y){
    for(int i=0; i<positions.size(); i++)
    {
        if(positions[i].first == x && positions[i].second ==y)
        {
            hits[i]= true;
            return;
        }
    }
}

//check if every cell is hitted of a single ship
bool Ship::isSunk(){
    for(bool k: hits)
    {
        if(k == false)
        return false;
    }
    return true;
}



