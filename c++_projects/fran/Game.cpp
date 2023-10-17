//
// Created by Adam Franc on 29. 10. 2020.
//

#include <iostream>
#include "Game.h"

Game::Game(const std::string &sudokuFileName) {
    this->sudokuFileName = sudokuFileName;
    sudoku = new Sudoku();
}

void Game::printStart() const {
    std::cout << "Game Started! Replace all 0 with a number 1-4." << std::endl;
}

void Game::printOptions() const {
    std::cout << "ROW | COLUMN | NUMBER" << std::endl;
}

void  Game::printEnd() const {
    std::cout << "End of Game. Thanks for playing" << std::endl;
}

void Game::start() {
    sudoku->loadSudoku(sudokuFileName);

    while (true) {
        sudoku->print();
        printOptions();
        std::array<int, 3> input = userInput();
        processInput(input);
    }
}

std::array<int, 3> Game::userInput() const {
    std::array<int, 3> input;
    for (int i = 0; i <= 2; i++) {
        std::cin >> input[i];
    }
    return std::array<int, 3>();
}

void Game::processInput(std::array<int, 3> input){
    if (input[0] == 999) {
        printEnd();
        exit(0);
    } else {
        tryFillSudoku(input[0], input[1], input[2]);
    }
}

void Game::tryFillSudoku(int x, int y, int numToFill) {
    try {
        sudoku->updateField(x, y, numToFill);
    } catch (std::out_of_range& e) {
        std::cerr << e.what() << std::endl;
    }
}

