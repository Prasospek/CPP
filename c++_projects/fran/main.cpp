#include "Game.h"

int main() {

    Game* game = new Game(R"(D:\ccc++\CPP_TEST\sudoku.txt)");
    game->start();

    return 0;
}
