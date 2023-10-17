#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Player.h"

class Game {
public:
    void play(Board& board, Player& player);
};

#endif // GAME_H
