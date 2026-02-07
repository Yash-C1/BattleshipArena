#include "ship.h"
#include <vector>
#include <utility>
#include <stdexcept>

// Constructor
Ship::Ship(const std::string &name, int size)
{
    this->name = name;
    this->size = size;
    // initialize hits to avoid runtime error!
    hits.resize(size, false);
}

// Set ship positions
void Ship::place_of_ship(const std::vector<std::pair<int,int> >& positions)
{
    if(positions.size() != static_cast<size_t>(size))
    {
        throw std::runtime_error("Ship placement does not match ship size!");
    }
    this->positions = positions;
}

// Check if cell belongs to this ship
bool Ship::cellOccupied(int x, int y) const
{
    for(const auto& p : positions)
    {
        if(p.first == x && p.second == y)
        {
            return true;
        }
    }
    return false;
}

// Mark hit on ship
void Ship::hit_position(int x, int y)
{
    for(int i = 0; i < positions.size(); i++)
    {
        if(positions[i].first == x && positions[i].second == y)
        {
            hits[i] = true;
            return;
        }
    }
}

// Check if ship is sunk
bool Ship::isSunk() const
{
    for(bool h : hits)
    {
        if(!h)
            return false;
    }
    return true;
}

int Ship::get_size() {
    return size;
}