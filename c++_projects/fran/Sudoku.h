//
// Created by Adam Franc on 29. 10. 2020.
//

#ifndef CPP_TEST_SUDOKU_H
#define CPP_TEST_SUDOKU_H

#include <array>
#include <string>

class Sudoku {
public:
    static const int sudokuSize = 4;
    static const char sudokuSeparator = '*';
    static const int sudokuEmptyField = '0';
private:
    std::array<std::array<char, sudokuSize>, sudokuSize> sudoku;
public:
    Sudoku();
    bool checkField(int x, int y, int numToFill) const;
    void updateField(int x, int y, int numToFill);
    void loadSudoku(const std::string& fileName);
    void print() const;
};


#endif //CPP_TEST_SUDOKU_H
