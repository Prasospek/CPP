//
// Created by Koty97 on 29.10.2020.
//

#include "Sudoku.h"

Sudoku::Sudoku(std::string filePath) {
    Loader *l = new Loader(filePath);
    board = l->loadFile();
    size = board.size() / 2;
}

void Sudoku::printBoard() const{
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.at(i).size(); j++) {
            if (board.at(i).at(j) == 0)
                std::cout << "_";
            else
                std::cout << board.at(i).at(j);
            if (j == size - 1)std::cout << "|";
        }
        std::cout << std::endl;
        if (i == size - 1)std::cout << "------" << std::endl;
    }
}

void Sudoku::startGame() {
    printBoard();
    while (!victory) {
        turn();
        printBoard();
        if (checkWin())victory = true;
    }
    if(victory) std::cout << "You have won this game, congratulations!" << std::endl;
}

void Sudoku::turn() {
    std::cout << "Enter coord X Y and new Value, each on its separate line" << std::endl;
    int x;
    int y;
    int v = 0;
    std::cin >> x;
    std::cin >> y;
    while(v<=0 || v>size*size) {
        std::cin >> v;
    }
    try {
        board.at(x).at(y) = v;
    }
    catch (const std::out_of_range ex) {
        std::cerr << "Error while accesing board at "<<x<<","<<y<<": " << ex.what() << '\n';
    }
}

bool Sudoku::checkWin() const{
    int sum = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            sum += board.at(i).at(j);
        }
    }
    if (sum != getSum(size * 2))return false;//Q1
    sum = 0;
    for (int i = 0; i < size; i++) {
        for (int j = size; j < board.size(); j++) {
            sum += board.at(i).at(j);
        }
    }
    if (sum != getSum(size * 2))return false;//Q2
    sum = 0;
    for (int i = size; i < board.size(); i++) {
        for (int j = 0; j < size; j++) {
            sum += board.at(i).at(j);
        }
    }
    if (sum != getSum(size * 2))return false;//Q3
    sum = 0;
    for (int i = size; i < board.size(); i++) {
        for (int j = size; j < board.size(); j++) {
            sum += board.at(i).at(j);
        }
    }
    if (sum != getSum(size * 2))return false;//Q4
    sum = 0;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            sum += board.at(i).at(j);
        }
        if (sum != getSum(size * 2))return false;//rows
        sum = 0;
    }
    sum = 0;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            sum += board.at(j).at(i);
        }
        if (sum != getSum(size * 2))return false;//rows
        sum = 0;
    }
    return true;
}

int Sudoku::getSum(int x)const {
    int res = 0;
    for (int i = x; i > 0; i--) {
        res += i;
    }
    return res;
}
