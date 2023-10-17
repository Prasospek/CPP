#ifndef PLAYER_H
#define PLAYER_H

#include "Board.h"

class Player {
public:
    Player(Board& board);
    void makeMove(char direction);
    char getInput();

private:
    Board& gameBoard;
};

#endif // PLAYER_H
