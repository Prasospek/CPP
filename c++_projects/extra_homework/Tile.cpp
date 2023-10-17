#include "Tile.h"

Tile::Tile(int val) : value(val) {}

Tile::Tile() : value(0) {}  // Default constructor

int Tile::getValue() const {
    return value;
}

void Tile::setValue(int val) {
    value = val;
}
