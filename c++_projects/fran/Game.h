//
// Created by Adam Franc on 29. 10. 2020.
//

#ifndef CPP_TEST_GAME_H
#define CPP_TEST_GAME_H

#include <string>
#include "Sudoku.h"

class Game {
private:
    std::string sudokuFileName;
    Sudoku* sudoku;

    void printOptions() const;
    void printStart() const;
    std::array<int, 3> userInput() const;
    void processInput(std::array<int, 3> input);
    void tryFillSudoku(int x, int y, int numToFill);
    void printEnd() const;

public:
    Game(const std::string& sudokuFileName);
    void start();

};


#endif //CPP_TEST_GAME_H
