#include <iostream>
#include "Game.h"


int main() {
    Board board;
    Player player(board);
    Game game;

    //play(board, player);
    game.play(board, player);

    return 0;
}
