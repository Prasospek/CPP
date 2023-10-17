#ifndef TILE_H
#define TILE_H

class Tile {
public:
    Tile(int val);
    Tile();  // Default constructor
    int getValue() const;
    void setValue(int val);

private:
    int value;
};

#endif // TILE_H
