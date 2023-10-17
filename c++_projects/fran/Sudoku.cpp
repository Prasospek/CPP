//
// Created by Adam Franc on 29. 10. 2020.
//

#include "Sudoku.h"
#include "Position.h"
#include <iostream>
#include <fstream>

Sudoku::Sudoku() {
    sudoku = std::array<std::array<char, sudokuSize>, sudokuSize>();
}

void Sudoku::print() const {
    for (int x = 0; x < sudoku.size(); x++) {
        for (int y = 0; y < sudoku.at(x).size(); y++) {
            std::cout << sudoku.at(x).at(y);
        }
        std::cout << std::endl;
    }
}

void Sudoku::updateField(int x, int y, int numToFill) {
    if (!checkField(x, y, numToFill)) {
        throw std::out_of_range("Invalid input!");
    }



}

bool Sudoku::checkField(int x, int y, int numToFill) const {
    return (x <= 4 and x > 0 and y <= 4 and y > 0 and numToFill <= 4 and numToFill > 0);
}

void Sudoku::loadSudoku(const std::string &fileName) {
    std::ifstream file(fileName);
    std::string line;

    if (!file.is_open()) {
        throw std::invalid_argument("File " + fileName + " not found/cannot be opened!");
    }

    int x = 0;

    while (getline(file, line)) {
        int y = 0;

        for (auto &element: line) {
            sudoku.at(x).at(y) = element;
            y++;
        }

        x++;

    }

}
