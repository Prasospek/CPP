// Board.h

#ifndef BOARD_H
#define BOARD_H

#include "Tile.h"

class Board {
public:
    Board();
    void display() const;
    bool move(char direction);
    bool isSolved() const;

private:
    Tile tiles[3][3];
    int emptyRow;
    int emptyCol;
};

#endif // BOARD_H
