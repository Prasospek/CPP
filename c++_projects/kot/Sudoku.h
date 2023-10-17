//
// Created by Koty97 on 29.10.2020.
//

#ifndef TEST1_SUDOKU_H
#define TEST1_SUDOKU_H
#include <iostream>
#include <array>
#include "Loader.h"

class Sudoku {
    std::array<std::array<int,4>,4> board;
    int size;
    bool victory;
public:
    Sudoku(std::string);
    void startGame();
    void turn();
    void printBoard()const;
    bool checkWin()const;
    int getSum(int x)const;
};


#endif //TEST1_SUDOKU_H
