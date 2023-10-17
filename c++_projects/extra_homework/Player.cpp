#include "Player.h"
#include <iostream>

Player::Player(Board& board) : gameBoard(board) {}

void Player::makeMove(char direction) {
    if (gameBoard.move(direction)) {
        gameBoard.display();
        if (gameBoard.isSolved()) {
            std::cout << "Congratulations! You've won!" << std::endl;
        }
    } else {
        std::cout << "Invalid move. Please use ASWD keys." << std::endl;
    }
}

char Player::getInput() {
    char move;
    std::cout << "Enter your move (ASWD): ";
    std::cin >> move;
    return move;
}
