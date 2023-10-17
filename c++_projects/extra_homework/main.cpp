#include "Board.h"
#include "Player.h"
#include <iostream>

int main() {
    Board board;
    Player player(board);

    // Display the initial game board
    board.display();

    while (true) {
        char move = player.getInput();

        if (move == 'q') {
            std::cout << "You quit the game." << std::endl;
            break;
        }

        player.makeMove(move);

        if (board.isSolved()) {
            std::cout << "Congratulations! You've won!" << std::endl;
            break;
        }
    }

    return 0;
}
