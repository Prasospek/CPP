// Board.cpp

#include "Board.h"
#include "Tile.h"
#include <iostream>

// Board.cpp

//Board::Board() : emptyRow(0), emptyCol(0) {
//    int val = 1;
//    for (int row = 0; row < 3; row++) {
//        for (int col = 0; col < 3; col++) {
//            if (row == 0 && col == 0) {
//                tiles[row][col] = Tile(0); // Initial empty space
//            } else {
//                tiles[row][col] = Tile(val);
//                val++;
//            }
//        }
//    }
//}

Board::Board() : emptyRow(0), emptyCol(0) {
    int val = 1;
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (row == 0 && col == 0) {
                tiles[row][col] = Tile(0); // Initial empty space
            } else {
                if (row == 0 && col == 1) {
                    tiles[row][col] = Tile(1);
                } else if (row == 0 && col == 2) {
                    tiles[row][col] = Tile(4);
                } else if (row == 1 && col == 0) {
                    tiles[row][col] = Tile(2);
                } else if (row == 1 && col == 1) {
                    tiles[row][col] = Tile(3);
                } else if (row == 1 && col == 2) {
                    tiles[row][col] = Tile(5);
                } else if (row == 2 && col == 0) {
                    tiles[row][col] = Tile(8);
                } else if (row == 2 && col == 1) {
                    tiles[row][col] = Tile(7);
                } else if (row == 2 && col == 2) {
                    tiles[row][col] = Tile(6);
                }
            }
        }
    }
}


void Board::display() const {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            std::cout << (tiles[row][col].getValue() == 0 ? " - " : " " + std::to_string(tiles[row][col].getValue()) + " ");
        }
        std::cout << std::endl;
    }
}

bool Board::move(char direction) {
    int newRow = emptyRow;
    int newCol = emptyCol;

    switch (direction) {
        case 'a': // Left
            newCol = emptyCol - 1;
            break;
        case 's': // Down
            newRow = emptyRow + 1;
            break;
        case 'd': // Right
            newCol = emptyCol + 1;
            break;
        case 'w': // Up
            newRow = emptyRow - 1;
            break;
        default:
            return false;
    }

    if (newRow >= 0 && newRow < 3 && newCol >= 0 && newCol < 3) {
        tiles[emptyRow][emptyCol] = tiles[newRow][newCol];
        tiles[newRow][newCol] = Tile(0);
        emptyRow = newRow;
        emptyCol = newCol;
        return true;
    }

    return false;
}

bool Board::isSolved() const {
    int val = 1;
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (row == 2 && col == 2) {
                if (tiles[row][col].getValue() != 0) {
                    return false;
                }
            } else if (tiles[row][col].getValue() != val) {
                return false;
            }
            val++;
        }
    }
    return true;
}

